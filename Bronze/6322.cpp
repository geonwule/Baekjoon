#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fn(int a, int b, int c)
{
    
}

int main()
{
    int idx = 0;
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (!a && !b && !c)
            break;

        double res;
        char alpha;
        if (a == -1)
        {
            alpha = 'a';
            res = fn(a, b, c);
        }
        else if (b == -1)
        {
            alpha = 'b';
            res = fn(b, a, c);        
        }
        else
        {
            alpha = 'c';
            res = fn(c, a, b);
        }

        cout << "Triangle #" << ++idx << endl;
        if (res == -1)
        {
            cout << "Impossible." << endl;
        }
        else
        {
            cout << alpha << " = " << res << endl;
        }
    }
    return 0;
}