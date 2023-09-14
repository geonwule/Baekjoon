#include <iostream>
#include <vector>
#include <algorithm>

struct Discuss
{
    int start, end;
};

int n;

bool    compare(Discuss& a, Discuss& b)
{
    if (a.end == b.end)
    {
        return (a.start < b.start);
    }
    return (a.end < b.end);
}

int main()
{
    std::cin >> n;
    std::vector<Discuss>    arr(n);
    for (int i = 0; i < n; i++)
    {
        int s, e;
        std::cin >> s >> e;
        arr[i].start = s;
        arr[i].end = e;
    }
    std::sort(arr.begin(), arr.end(), compare);

    int cnt = 0;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr <= arr[i].start)
        {
            cnt++;
            curr = arr[i].end;
        }
    }

    std::cout << cnt;
}
    // for (int i = 0; i < n; i++)
    // {
    //     std::cout << "첫 요소 : " << arr[i].start << ", 두번째 요소 :" << arr[i].end << std::endl;
    // }


/*
#include <iostream>
#include <vector>
#include <utility>

int n;
std::vector<std::pair<int, int> >    arr;
int max = -1;

void    set_input(void)
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        std::cin >> start >> end;
        arr.push_back(std::make_pair(start, end));
        if (max < start)
            max = start;
    }
}

int ret = 0;

bool    visited[100001] = {false, };

void    recur(int start_time, int cnt)
{
    if (start_time > max)
    {
        if (cnt > ret)
        {
            ret = cnt;
        }
        return ;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (start_time <= arr[i].first && !visited[i])
        {
            visited[i] = true;
            recur(arr[i].second, cnt + 1);
        }
        visited[i] = false;
    }
}

int main()
{
    set_input();
    recur(0, 0);
    std::cout << ret;
}
*/
