#include <iostream>

#define Max 201

int n, m, arr[Max], visit[Max];

#include <queue>
using namespace std;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    
    int cnt_change = 0;
    queue<int> q;
    q.push(m);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if (tmp == arr[tmp] || visit[tmp])
            continue;
        visit[tmp] = 1;
        cnt_change++;
        q.push(arr[tmp]);
    }
    cout << cnt_change;
}