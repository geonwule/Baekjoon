#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

int test = 0;
ull solution(ull A, ull B, ull C)
{
    // cout << "cnt = " << ++test << '\n'; //test
    if (B == 0)
        return 1;

    ull half = solution(A, B / 2, C);
    ull result = half * half % C;
    // ull result = solution(A, B / 2, C) * solution(A, B / 2, C) % C;
    // ull result = 1;
    // result = result * solution(A, half, C) % C;
    // result = result * solution(A, half, C) % C;

    if (B % 2 == 1)
    {
        result = result * A % C;
    }

    // cout << "result = " << result << '\n';
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull A, B, C;
    cin >> A >> B >> C;
    printf("%llu", solution(A,B,C));
    // cout << solution(A, B, C);
    // printf("%.0f", solution(A, B, C));

    return 0;
}