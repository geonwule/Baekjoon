#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[5][5];

void input()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
}

vector<string> v_res;

bool checkDouble(string &num)
{
    if (find(v_res.begin(), v_res.end(), num) != v_res.end())
        return true;
    return false;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


struct Info
{
    int x, y;
    string s_num;
};
#include <queue>
queue<Info> q;

int cnt = 0;
void printInfo(Info& info)
{
    cout << "x = " << info.x << " y = " << info.y << " num = " << info.s_num << '\n';
    // if (++cnt == 5)
        // exit(0);
}

void bfs(int y, int x)
{
    Info info_init;
    info_init.x = x;
    info_init.y = y;
    info_init.s_num = arr[y][x] + '0';
    q.push(info_init);
    while(q.empty()==false)
    {
		Info info=q.front();
		q.pop();
		if(info.s_num.size()==6)
		{
			if (checkDouble(info.s_num) == false)
                v_res.push_back(info.s_num);
            cout << "check = " << checkDouble(info.s_num) << ' ';
            printInfo(info);
			continue;
		}
		for(int i=0;i<4;i++)
		{
			int nx=info.x+dx[i];
			int ny=info.y+dy[i];
			if(nx<0||ny<0||nx>=5||ny>=5)
			{
				continue;
			}
			Info ninfo;
			ninfo.x=nx;
			ninfo.y=ny;
			string tmp = info.s_num;
            tmp += (arr[ny][nx]+'0');
			ninfo.s_num= tmp;
			q.push(ninfo);
		}
    }

    
}

void output()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bfs(i, j);
        }
    }

    cout << v_res.size();
}

int main()
{
    input();
    output();    
}