#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define Max 50

int N, price = 0, purePrice = 0;
#include <sstream>

struct Person
{
    int price, delevery;
};

vector<Person> varr;

void printV(vector<Person> tmp)
{
    for (auto i = tmp.begin(); i != tmp.end(); i++)
    {
        cout << (*i).price << ' ' << (*i).delevery << '\n';
    }
}

int comp(Person a, Person b)
{
    return (a.price < b.price);
}

void input()
{
    for (int i = 0; i < N; i++)
    {
        Person tmp;
        cin >> tmp.price >> tmp.delevery;
        varr.push_back(tmp);
    }
    sort(varr.begin(), varr.end(), comp);
    // printV(varr);
}

void output()
{
    for (int i = 0; i < N; i++)
    {
        int tmpPrice = varr[i].price;
        int t_pure = 0;
        for (int j = i; j < N; j++)
        {
            if (varr[j].price >= tmpPrice && tmpPrice - varr[j].delevery > 0)
            {
                t_pure += tmpPrice - varr[j].delevery;
            }
        }
        if (t_pure > purePrice)
        {
            purePrice = t_pure;
            price = tmpPrice;
        }
    }
    cout << price;
}
int main()
{
    cin >> N;
    input();
    output();
}