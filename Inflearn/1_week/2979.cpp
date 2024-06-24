/*inflearn*/
#include <iostream>

using namespace std;

int main()
{
    int A, B, C, a, b, cnt[101] = {0, }, answer = 0;
    cin >> A >> B >> C;
    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b;
        for (int j = a; j < b; j++)
            cnt[j]++;
    }

    for (int i = 1; i < 100; i++)
    {
        switch(cnt[i])
        {
            case 0:
            break;

            case 1:
            answer += cnt[i] * A;
            break;

            case 2:
            answer += cnt[i] * B;
            break;

            case 3:
            answer += cnt[i] * C;
            break;
        }
    }

    cout << answer;
}

/*my try*/
// #include <iostream>
// #include <vector>

// using namespace std;

// struct Fee
// {
//     int a, b, c;
// };

// struct Car
// {
//     int arrive, left;
// };

// int solution(const Fee &fee, const vector<Car>& cars)
// {
//     int answer = 0;
//     int min_time = 100, max_time = 1;

//     for (const Car &car : cars)
//     {
//         min_time = min(min_time, car.arrive);
//         max_time = max(max_time, car.left);
//     }
    
//     for (int i = min_time; i < max_time; i++)
//     {
//         // cout << "i = " << i << '\n'; //test
//         int cnt = 0;
//         for (const Car &car : cars)
//         {
//             if (car.arrive <= i && car.left > i)
//                 cnt++;
//         }

//         switch(cnt)
//         {
//             case 1:
//             answer += fee.a * cnt;
//             // cout << "cnt = " << cnt << ", answer = " << answer << '\n'; // test
//             break;

//             case 2:
//             answer += fee.b * cnt;
//             // cout << "cnt = " << cnt << ", answer = " << answer << '\n'; // test
//             break;

//             case 3:
//             answer += fee.c * cnt;
//             // cout << "cnt = " << cnt << ", answer = " << answer << '\n'; // test
//             break;

//             default:
//             break;
//         }
//     }

//     return answer;
// }

// int main()
// {
//     Fee fee;
//     vector<Car> cars(3);
//     cin >> fee.a >> fee.b >> fee.c;
//     for (Car &car : cars)
//         cin >> car.arrive >> car.left;
    
//     cout << solution(fee, cars);
//     return 0;
// }

