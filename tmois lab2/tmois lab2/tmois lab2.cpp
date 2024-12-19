// tmois lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <locale>
using namespace std;

void gr_output(vector<vector<int>> a)
{
    cout << "{" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << "<";

        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j];
            if (j == 0) cout << ", ";
            if (j == 1) cout << ">" << endl;
        }
    }
    cout << "}" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
}

void proj_output(vector<int> a)
{
    cout << "{";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
        if (i != a.size() - 1)
            cout << ", ";
    }
    cout << "}";
    cout << endl;

    cout << "-----------------------------------------------------------------------" << endl;
}

vector<vector<int>> sort(vector<vector<int>> a)
{
    vector<vector<int>> result;
    int contain = 0;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < result.size(); j++)
        {
            if (a[i][0] == result[j][0] && a[i][1] == result[j][1])
                contain++;
        }

        if (contain == 0)
            result.push_back({ a[i][0], a[i][1] });

        contain = 0;
    }

    return result;
}

vector<int> sort2(vector<int> a)
{
    vector<int> result;
    int contain = 0;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < result.size(); j++)
        {
            if (a[i] == result[j])
                contain++;
        }

        if (contain == 0)
            result.push_back(a[i]);

        contain = 0;
    }

    return result;
}

vector<int> proj_on_axis(vector<vector<int>> a, int axis)
{
    vector<int> result;
    for (int i = 0; i < a.size(); i++)
    {
        result.push_back(a[i][axis - 1]);
    }

    return sort2(result);
}

vector<vector<int>> inversion(vector<vector<int>> a)
{
    vector<vector<int>> result;
    result = a;
    for (int i = 0; i < a.size(); i++)
    {
        result[i][1] = a[i][0];
        result[i][0] = a[i][1];
    }

    return result;
}

vector<vector<int>> composition(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> result;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i][1] == b[j][0])
                result.push_back({ a[i][0], b[j][1] });
        }
    }

    return sort(result);
}

vector<vector<int>> dek_multiplication(vector<int> a, vector<int> b)
{
    vector<vector<int>> result;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            result.push_back({ a[i], b[j] });
        }
    }

    return sort(result);
}

int main()
{
    setlocale(LC_ALL, "RU");

    //Вектор для промежуточных значений
    vector<int> projection;
    vector<vector<int>> graf;
    //Переменные
    int P_length;
    int Q_length;
    int choice;
    int buf1, buf2;

    vector<vector<int>> P;
    vector<vector<int>> Q;

    cout << "Как вы хотите ввести графики?" << endl;
    cout << "1. Вручную." << endl << "2. Высказыванием." << endl;
    do {
        cout << "Ваш выбор: ";
        cin >> choice;
    } while (choice < 1 || choice > 2);

    if (choice == 1)
    {
        cout << "Введите мощность графика P: ";
        cin >> P_length;


        cout << "Вводите график P: " << endl;
        for (int i = 0; i < P_length; i++)
        {
             cin >> buf1;
             cin >> buf2;

             P.push_back({ buf1, buf2 });
        }
        cout << "-----------------------------------------------------------------------" << endl;

        while (P != sort(P))
        {
            cout << "Ошибка ввода! Проверьте правильность введенных данных (исключите повторяющиеся пары) и повторите ввод." << endl;
            cout << "Вводите график P: " << endl;
            for (int i = 0; i < P_length; i++)
                {
                    cin >> buf1;
                    cin >> buf2;

                    P.push_back({ buf1, buf2 });
                }
            cout << "-----------------------------------------------------------------------" << endl;
        }

        cout << "Ваш график P:" << endl;
        gr_output(P);

        cout << "Введите мощность графика Q: ";
        cin >> Q_length;

        cout << "Вводите график Q: " << endl;
        for (int i = 0; i < Q_length; i++)
            {
                cin >> buf1;
                cin >> buf2;

                Q.push_back({ buf1, buf2 });
            }
        cout << "-----------------------------------------------------------------------" << endl;

        while (Q != sort(Q))
        {
            cout << "Ошибка ввода! Проверьте правильность введенных данных (исключите повторяющиеся пары) и повторите ввод." << endl;
            cout << "Вводите график Q: " << endl;
            for (int i = 0; i < Q_length; i++)
                {
                    cin >> buf1;
                    cin >> buf2;

                    Q.push_back({ buf1, buf2 });
                }
            cout << "-----------------------------------------------------------------------" << endl;
        }

        cout << "Ваш график Q:" << endl;
        gr_output(Q);
    }
    else
    {
        cout << "Будет использовано высказывание x = n, y = 2n." << endl;
        cout << "Введите мощность графика P: ";
        cin >> P_length;


        cout << "Введите мощность графика Q: ";
        cin >> Q_length;


        for (int n = 0; n < P_length; n++)
        {
            P.push_back({ n, (2*n) });
        }

        for (int n = 0; n < Q_length; n++)
        {
            Q.push_back({ n, (2*n) });
        }

        cout << "Ваш график P:" << endl;
        gr_output(P);

        cout << "Ваш график Q:" << endl;
        gr_output(Q);
    }
//ОПЕРАЦИИ:

    //ОБЛАСТЬ ОПРЕДЕЛЕНИЯ:

    cout << "Область определения P (проекция на ось Ox):" << endl;
    
    projection = proj_on_axis(P, 1);
    proj_output(projection);

    cout << "Область определения Q (проекция на ось Ox):" << endl;

    projection = proj_on_axis(Q, 1);
    proj_output(projection);

    //МНОЖЕСТВО ЗНАЧЕНИЙ:

    cout << "Множество значений P (проекция на ось Oy):" << endl;

    projection = proj_on_axis(P, 2);
    proj_output(projection);

    cout << "Множество значений Q (проекция на ось Oy):" << endl;

    projection = proj_on_axis(Q, 2);
    proj_output(projection);

    //ИНВЕРСИЯ:

    cout << "Инверсия графика P: " << endl;

    graf = inversion(P);
    gr_output(graf);

    cout << "Инверсия графика Q: " << endl;

    graf = inversion(Q);
    gr_output(graf);

    //КОМПОЗИЦИЯ:

    cout << "Композиция графиков P·Q:" << endl;

    graf = composition(P, Q);
    gr_output(graf);

    cout << "Композиция графиков Q·P:" << endl;
    
    graf = composition(Q, P);
    gr_output(graf);

    //ДЕКАРТОВО ПРОИЗВЕДЕНИЕ:

    cout << "Декартово произведение проекций графиков P и Q на Ox:" << endl;
    
    graf = dek_multiplication( proj_on_axis(P, 1), proj_on_axis(Q, 1) );
    gr_output(graf);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
