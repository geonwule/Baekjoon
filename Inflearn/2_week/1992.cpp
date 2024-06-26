#include <iostream>
#include <vector>

using namespace std;

struct Pos
{
    int x, y;
};


// int tcnt = 0; //test
void backTracking(const Pos MIN, const Pos MAX, vector<string> &v, string& answer)
{
    // cout << "tcnt = " << ++tcnt << '\n'; //test
    bool all_same = true;
    char stand = v[MIN.y][MIN.x];
    for (int y = MIN.y; y < MAX.y; y++)
    {
        for (int x = MIN.x; x < MAX.x; x++)
        {
            if (v[y][x] != stand)
            {
                all_same = false;
                break;
            }
        }
        if (!all_same)
            break;
    }

    if (all_same)
    {
        answer += stand;
    }
    else
    {
        int minX = MIN.x, minY = MIN.y;
        int maxX = MAX.x, maxY = MAX.y;

        answer += '(';
        backTracking(MIN, {(minX + maxX) / 2, (minY + maxY) / 2}, v, answer);
        backTracking({(minX + maxX) / 2, minY}, {maxX, (minY + maxY) / 2}, v, answer);
        backTracking({minX, (minY + maxY) / 2}, {(minX + maxX) / 2, maxY}, v, answer);
        backTracking({(minX + maxX) / 2, (minY + maxY) / 2}, MAX, v, answer);
        answer += ')';
    }
}

string solve2(int o_x, int o_y, const int size, const vector<string>&v)
{
    char target = v[o_y][o_x];
    for (int y = o_y; y < o_y + size; y++)
    {
        for (int x = o_x; x < o_x + size; x++)
        {
            if (v[y][x] != target)
            {
                string ret;
                ret += "(";

                ret += solve2(o_x, o_y, size / 2, v);
                ret += solve2(o_x + size / 2, o_y, size / 2, v);
                ret += solve2(o_x, o_y + size / 2, size / 2, v);
                ret += solve2(o_x + size / 2, o_y + size / 2, size / 2, v);

                ret += ")";
                return ret;
            }
        }
    }

    return string(1, target);
}

string solution(const int N, vector<string> &v)
{
    string answer;

    // backTracking({0, 0}, {N, N}, v, answer);
    answer = solve2(0, 0, N, v);
    return answer;
}

int main()
{
    int N;
    cin >> N;
    vector<string> v(N);
    for (string &s : v)
        cin >> s;

    cout << solution(N, v);

    return 0;
}