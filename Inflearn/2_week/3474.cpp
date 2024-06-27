#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll factori(const int N)
{
    ll ans = 1;
    for (ll i = 2; i <= N; i++)
        ans *= i;
    return ans;
}


ll solve(const int N)
{
    // cout << factori(N) << '\n'; //test

    ll zero_cnt = 0;
    zero_cnt += N / 5;
    
    int cpN = N;
    int i = 0;

    for (ll add = 25; add <= cpN; add *= 5)
    {
        zero_cnt += ++i;
        for (ll j = 2; add * j <= cpN; j++)
        {
            if ((add * j) % (add * 5) == 0)
                continue;
            zero_cnt += i;
        }
    }

    return zero_cnt;
}

/*
25의 배수,
125의 배수,

공배수일경우 
*/

/* 60 = ans(14) , my(13)

60 / 5 = 12
25 ++ = 13

60! = 5! * 10! * ... 25! * ...  50! * 55! * 60!
      1     1         2         2?     1     1

*/

/*
5! = 5 * 4 * 3 * 2 * 1 = 20 * 6 = 120 = 1개

0이 나올수 있는 경우 = 2 * 5
즉  2의 갯수 5의 갯수 1쌍에 1개씩

2, 5의 갯수
1! = 2(0), 5(0)
2! = 1! + 2(1)
3! = 2! + 0
4! = 3! + 2(2)
5! = 4! + 5(1)
.
.
.
10억! = (10억 - 1)! + 10억의 (2의 갯수, 5의갯수)

8 % 2 == 0 ---- +1
8 /= 2;

4 % 2 == 0 ---- +1
4 /= 2;

2 % 2 == 0 ---- +1
2 /= 2;

1 % 2 == 1 ---- stop

N의 2의 갯수 = N % 2, N /= 2 while;
N의 5의 갯수 = N % 5, N /= 5 while;


1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = ---0
8! = ----0
9! = ----0
10! = ---00

2는 많다, 의 갯수가 즉 0의 갯수가 될수 있다.

2 = (1, 0)
4 = (2, 0)
5 = (0, 1) -> (3, 1)
6 = (1, 0)
8 = (3, 0)
10 = (1, 1) 


-> 즉 5의 배수 마다 0이 하나씩 는다.

그말은 N의 0의 갯수는
N / 5이고

N!의 0의 갯수는
(N-1)!의 0의 갯수 + N / 5; 이다.

5! = 1개

10! = 1개 + 5!개(1개) = 2개

15! = 1개 + 10!개 (2개) = 3개

20! = 1개 + 15!개 (3개) = 4개

25! = 1개 + 20!개 (4개) + 1개 = 6개

30! = 1개 + 25!개 (6개) = 7개

125! = 1개 +  .... + 2개

10억 / 5 = 2억
*/

int solve2(const int N)
{
    int cnt = 0;
    for (int i = 5; i <= N; i *= 5)
        cnt += N / i;
    
    return cnt;
}

int main()
{
    vector<int> answer;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        answer.push_back(solve2(N));
    }

    for(const int i : answer)
        cout << i << '\n';
    return 0;
}