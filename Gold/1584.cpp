#include <iostream>
#include <queue>
#include <deque>

using namespace std;

enum e_state
{
    SAFETY = 0,
    DANGER,
    DEATH,
};

#define MAP_MAX 500

int _map[MAP_MAX + 1][MAP_MAX + 1] = {SAFETY, };
int visit[MAP_MAX + 1][MAP_MAX + 1];
int num_danger, num_death;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

#define TEST_MAX 10
void printMap();

struct Info
{
    int x, y;
    int lost_life;

    Info(int x_, int y_, int lost_life_) : x(x_), y(y_), lost_life(lost_life_) {}
};

void output()
{
    long long res = -1;
    deque<Info> dq;

    visit[0][0] = 1;
    Info start(0, 0, 0);
    dq.push_back(start);

    while (!dq.empty())
    {
        Info tmp = dq.front();
        dq.pop_front();

        if (tmp.x == MAP_MAX && tmp.y == MAP_MAX)
        {
            res = tmp.lost_life;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            int nlost_life = tmp.lost_life;
            if (nx >= 0 && ny >= 0 && nx <= MAP_MAX && ny <= MAP_MAX && visit[ny][nx] == 0 && _map[ny][nx] != DEATH)
            {
                visit[ny][nx] = 1;
                if (_map[ny][nx] == DANGER)
                {
                    nlost_life += 1;
                    dq.push_back(Info(nx, ny, nlost_life));
                }
                else
                {
                    dq.push_front(Info(nx, ny, nlost_life));
                }
            }
        }
    }

    cout << res;
}

void setMap(int x_start, int y_start, int x_end, int y_end, e_state state)
{
    for (int y = y_start; y <= y_end; ++y)
    {
        for (int x = x_start; x <= x_end; ++x)
        {
            _map[y][x] = state;
        }
    }
}

void input()
{
    cin >> num_danger;
    for (int i = 0; i < num_danger; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        setMap(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2), DANGER);
    }
    cin >> num_death;
    for (int i = 0; i < num_death; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        setMap(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2), DEATH);
    }
}


int main()
{
    input();
    output();
    // printMap();
}

void printMap()
{
    cout << "==map==\n";
    for (int y = 0; y <= TEST_MAX; ++y)
    {
        for (int x = 0; x <= TEST_MAX; ++x)
        {
            cout << _map[y][x];
        }
        cout << '\n';
    }

    cout << "==visit==\n";
    for (int y = 0; y <= TEST_MAX; ++y)
    {
        for (int x = 0; x <= TEST_MAX; ++x)
        {
            cout << visit[y][x];
        }
        cout << '\n';
    }
}