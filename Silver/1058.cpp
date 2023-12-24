#include <iostream>

using namespace std;

#define Max 50

bool visit[Max];

int relation[Max][Max], numFriend = 0, N;

void initVisit()
{
    for (int i = 0; i < N; i++)
    {
        visit[i] = false;
    }
}

void input()
{
    cin >> N;
    for (int y = 0; y < N; y++)
    {
        string tmp;
        cin >> tmp;
        for (int x = 0; x < N; x++)
        {
            relation[y][x] = tmp[x];
        }
    }
}

void dfs(int f, int &oneNumFriend)
{
    for (int ff = 0; ff < N; ff++)
    {
        if (relation[f][ff] == 'Y' && !visit[ff])
        {
            visit[ff] = true;
            oneNumFriend++;
        }
    }
}

void output()
{
    for (int y = 0; y < N; y++)
    {
        int oneNumFriend = 0;
        initVisit();
        visit[y] = true; // myself
        for (int x = 0; x < N; x++)
        {
            // if (relation[y][x] == 'Y' && !visit[x])
            // {
            //     visit[x] = true;
            //     oneNumFriend++;
            //     dfs(x, oneNumFriend);
            // }
            if (relation[y][x] == 'Y')
            {
                if (!visit[x]) // 바꾼 지점
                    oneNumFriend++;
                visit[x] = true;
                dfs(x, oneNumFriend);
            }
        }
        if (numFriend < oneNumFriend)
            numFriend = oneNumFriend;
    }

    cout << numFriend;
}

int main()
{
    input();
    output();
}
