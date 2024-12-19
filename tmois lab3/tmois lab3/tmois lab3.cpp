#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;
void Sort(vector<int>& arr)
{
    vector<int> result; // Вектор для хранения уникальных элементов

    for (int i = 0; i < arr.size(); ++i)
    {
        bool isUnique = true; // Флаг для проверки уникальности элемента
        // Проверяем, существует ли элемент в векторе уникальных элементов
        for (int j = 0; j < result.size(); ++j)
        {
            if (arr[i] == result[j])
            {
                isUnique = false; // Элемент не уникален
                break;            // Прерываем цикл, если нашли дубликат
            }
        }
        // Если элемент уникальный, добавляем его в вектор уникальных элементов
        if (isUnique)
        {
            result.push_back(arr[i]);
        }
    }

    // Очищаем исходный вектор и заполняем его уникальными элементами
    arr.clear();
    arr = result;
}
void Sort(vector<pair<int, int>>& arr)
{
    vector<pair<int, int>> result;
    for (int i = 0; i < arr.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < result.size(); j++)
        {
            if (arr[i].first == result[j].first && arr[i].second == result[j].second)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            result.push_back(make_pair(arr[i].first, arr[i].second));
        }
    }
    arr.clear();
    arr = result;
}
vector<int> Union(vector<int> a, vector<int> b)
{
    vector<int> result;
    result = a;
    for (int i = 0; i < b.size(); i++)
    {
        result.push_back(b[i]);
    }
    Sort(result);
    return result;
}
vector<pair<int, int>> Union(vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    vector<pair<int, int>> result;
    result = a;
    for (int i = 0; i < b.size(); i++)
    {
        result.push_back(b[i]);
    }
    Sort(result);
    return result;
}
vector<int> Intersection(vector<int> a, vector<int> b)
{
    vector<int> result;
    for (int i = 0; i < a.size(); i++)
    {
        bool isSimple = false;
        for (int j = 0; j < b.size(); j++)
            if (a[i] == b[j])
            {
                isSimple = true;
                break;
            }
        if (isSimple)
        {
            result.push_back(a[i]);
        }
    }
    Sort(result);
    return result;
}
vector<pair<int, int>> Intersection(vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    vector<pair<int, int>> result;

    for (int i = 0; i < a.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i].first == b[j].first && a[i].second == b[j].second)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            result.push_back(a[i]);
        }
    }
    Sort(result);
    return result;
}
//vector<int> Residual(vector<int> a, vector<int> b)
//{
//    vector<int> result;
//    vector<int> intersected = Intersection(a, b);
//    for (int i = 0; i < a.size(); i++)
//    {
//        bool isSimple = true;
//        for (int j = 0; j < intersected.size(); j++)
//        {
//            if (a[i] == intersected[j])
//            {
//                isSimple = false;
//                break;
//            }
//        }
//        if (isSimple)
//        {
//            result.push_back(a[i]);
//        }
//    }
//    Sort(result);
//    return result;
//}

vector<int> Residual(vector<int> a, vector<int> b)
{
    vector<int> result;
    bool contain; //флаг вхождения

    for (int i = 0; i < a.size(); i++)
    {
        contain = false;
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j]) //условие, при котором a[i] не добавляется в результирующее множество
            {
                contain = true;
                break;
            }
        }

        if (contain == false) result.push_back(a[i]); //условие, при котором а[i] добавляется в результирующее множество
    }

    return result;
}
vector<pair<int, int>> Residual(vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    vector<pair<int, int>> result;
    bool contain;

    /*vector<pair<int, int>> intersected = Intersection(a, b);*/

    for (int i = 0; i < a.size(); i++)
    {
        bool contain = false;
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i].first == b[j].first && a[i].second == b[j].second)
            {
                contain = true;
                break;
            }
        }
        if (contain == false)
        {
            result.push_back(a[i]);
        }
    }
    /*Sort(result);*/
    return result;
}
vector<pair<int, int>> Composition(vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    vector<pair<int, int>> result;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i].second == b[j].first)
            {
                result.push_back(make_pair(a[i].first, b[j].second));
            }
        }
    }
    Sort(result);
    return result;
}
vector<pair<int, int>> inversion(vector<pair<int, int>> a)
{
    vector<pair<int, int>> result;
    for (int i = 0; i < a.size(); i++)
    {
        result.push_back(make_pair(a[i].second, a[i].first));
    }
    return result;
}
void vivod(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

class Combination
{
private:
    vector<int> X;
    vector<int> Y;
    vector<pair<int, int>> G;

public:
    vector<pair<int, int>> getG()
    {
        return G;
    }

    void enumereation()
    {
        int sizeX, sizeY, sizeG;
        cout << "enter size of X" << endl;
        while (!(cin >> sizeX) || cin.get() != '\n')
        {
            cout << "Error!" << endl
                << "Введите числовое значение : ";
            cin.clear();
            while (cin.get() != '\n')
                ;
        }

        cout << "enter size of Y" << endl;
        while (!(cin >> sizeY) || cin.get() != '\n')
        {
            cout << "Error!" << endl
                << "Введите числовое значение : ";
            cin.clear();
            while (cin.get() != '\n')
                ;
        }
        cout << "enter " << sizeX << " elements of X" << endl;
        for (int i = 0; i < sizeX; i++)
        {
            int temp;
            while (!(cin >> temp) || cin.get() != '\n')
            {
                cout << "Error!" << endl
                    << "Введите числовое значение : ";
                cin.clear();
                while (cin.get() != '\n')
                    ;
            }
            X.push_back(temp);
        }
        cout << "enter " << sizeY << " elements of Y " << endl;
        for (int i = 0; i < sizeY; i++)
        {
            int temp;
            while (!(cin >> temp) || cin.get() != '\n')
            {
                cout << "Error!" << endl
                    << "Введите числовое значение : ";
                cin.clear();
                while (cin.get() != '\n')
                    ;
            }
            Y.push_back(temp);
        }
        cout << "enter number of combinations" << endl;
        cin >> sizeG;
        cout << "enter " << sizeG << " elements of G (pairs)" << endl;
        for (int i = 0; i < sizeG; i++)
        {
            int temp1;
            int temp2;
            cin >> temp1 >> temp2;
            G.push_back(make_pair(temp1, temp2));
        }
    }
    void constant()
    {
        int sizeX, sizeY, sizeG;
        cout << "enter size of X" << endl;
        while (!(cin >> sizeX) || cin.get() != '\n')
        {
            cout << "Error!" << endl
                << "Введите числовое значение : ";
            cin.clear();
            while (cin.get() != '\n')
                ;
        }

        cout << "enter size of Y" << endl;
        while (!(cin >> sizeY) || cin.get() != '\n')
        {
            cout << "Error!" << endl
                << "Введите числовое значение : ";
            cin.clear();
            while (cin.get() != '\n')
                ;
        }

        cout << "enter x for formula: x+i for X and x+i+1 for Y" << endl;
        int x;
        while (!(cin >> x) || cin.get() != '\n')
        {
            cout << "Error!" << endl
                << "Введите числовое значение : ";
            cin.clear();
            while (cin.get() != '\n')
                ;
        }

        for (int i = 0; i < sizeX; i++)
        {
            X.push_back(x + i);
        }

        for (int i = 0; i < sizeX; i++)
        {
            Y.push_back(x + i + 1);
        }
        cout << "enter number of combinations" << endl;
        cin >> sizeG;
        cout << "combinations will be picked in this formula: 1-1 1-2 1-3...x-y";
        for (int i = 0; i < sizeG / sizeY + 1; i++)
        {
            for (int j = 0; j < sizeY; j++)
            {
                if (G.size() == sizeG)
                    return;
                G.push_back(make_pair(X[i], Y[j]));
            }
        }
    }
    void show()
    {
        cout << "\nX\n";
        for (int i = 0; i < X.size(); i++)
        {
            cout << X[i] << ' ';
        }
        cout << "\nY\n";
        for (int i = 0; i < Y.size(); i++)
        {
            cout << Y[i] << ' ';
        }
        cout << "\nG\n";
        for (int i = 0; i < G.size(); i++)
        {
            cout << G[i].first << " ," << G[i].second << endl;
        }
    }
    Combination operator+(const Combination c2) const
    {
        Combination res;
        res.X = Union(X, c2.X);
        res.Y = Union(Y, c2.Y);
        res.G = Union(G, c2.G);
        return res;
    }
    Combination operator-(const Combination c2) const
    {
        Combination res;
        res.X = Intersection(X, c2.X);
        res.G = Intersection(G, c2.G);
        res.Y = Intersection(Y, c2.Y);
        return res;
    }
    Combination operator/(const Combination c2) const
    {
        Combination res;
        res.X = Residual(X, c2.X);
        res.Y = Residual(Y, c2.Y);

        vector<pair<int, int>> temp;
        temp = Residual(G, c2.G);

        bool contain_X = false;
        bool contain_Y = false;

        for (int i = 0; i < temp.size(); i++)
        {
            
            contain_X = false;
            contain_Y = false;

            for (int j = 0; j < res.X.size(); j++)
            {
                if (temp[i].first == res.X[j])
                {
                    contain_X = true;
                }
            }
            
            for (int k = 0; k < res.Y.size(); k++)
            {
                if (temp[i].second == res.Y[k])
                {
                    contain_Y = true;
                }
            }

            if ((contain_Y == true) && (contain_X == true))
            {
                res.G.push_back(temp[i]);

            }
        }

        return res;
    }
    Combination Inversion()
    {
        Combination res;
        res.X = Y;
        res.Y = X;
        res.G = inversion(G);
        return res;
    }
    Combination operator*(const Combination c2) const
    {
        Combination res;
        res.X = X;
        res.Y = c2.Y;
        res.G = Composition(G, c2.G);
        return res;
    }
};
vector<int> view(Combination c, vector<int> a, int oper)
{
    vector<int> result;
    vector<pair<int, int>> g = c.getG();
    if (oper == 1)
    {
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < g.size(); j++)
            {
                if (a[i] == g[j].first)
                {
                    result.push_back(g[j].second);
                }
            }
        }
        Sort(result);
        return result;
    }
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < g.size(); j++)
            {
                if (a[i] == g[j].second)
                {
                    result.push_back(g[j].first);
                }
            }
        }
        Sort(result);
        return result;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    vector<int> a = { 1, 2, 3, 4 };
    Combination c1;
    c1.constant();
    c1.show();
    Combination c2;
    c2.constant();
    c2.show();
    cout << "\nunion: \n";
    (c1 + c2).show();
    cout << "\nintersection: \n";
    (c1 - c2).show();
    cout << "\nresidual: \n";
    (c1 / c2).show();
    cout << endl;
    (c2 / c1).show();
    cout << "\ncomposition:\n";
    (c1 * c2).show();
    cout << "\ninversion:\n";
    (c1.Inversion()).show();
    cout << endl;
    (c2.Inversion()).show();
    cout << "view\n";
    vivod(view(c1, a, 1));
    cout << endl;
    vivod(view(c2, a, 1));
    cout << "another view\n";
    vivod(view(c1, a, 0));
    cout << endl;
    vivod(view(c2, a, 0));
}
