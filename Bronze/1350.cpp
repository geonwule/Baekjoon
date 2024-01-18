#include <iostream>

using namespace std;
#define Max 50
int main()
{
    int N;
    cin >> N;

    size_t arr[Max];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    size_t cluster_size;
    cin >> cluster_size;

    size_t res = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0) // empty
            continue;
        else if (arr[i] <= cluster_size) //one time
            res += cluster_size;
        else if (arr[i] % cluster_size == 0) // 딱 나눠 떨떨어어질떄
            res += (arr[i] / cluster_size) * cluster_size;
        else
            res += (arr[i] / cluster_size + 1) * cluster_size; // 나머지가 있을때 + 1
    }

    cout << res;
}