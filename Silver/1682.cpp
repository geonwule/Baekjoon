#include <iostream>

using namespace std;

#include <deque>

void fA(deque<int> &a, deque<int> &b)
{
    std::swap(a, b);
}

void fB(deque<int> &a, deque<int> &b)
{
    int t = a.back();
    a.pop_back();
    a.push_front(t);

    t = b.back();
    b.pop_back();
    b.push_front(t);
}

void fC(deque<int> &a, deque<int> &b)
{
    int tmp1, tmp2;

    tmp1 = a[1];
    a[1] = a[2];

    tmp2 = b[1];
    b[1] = tmp1;

    tmp1 = b[2];
    b[2] = tmp2;

    a[2] = tmp1;
}

void fD(deque<int> &a, deque<int> &b)
{
    std::swap(a[0], b[3]);
}

struct Info
{
    deque<int> up_arr, down_arr;
    int L;

    Info &operator=(const Info &other)
    {
        // std::cout << "Copy assignment called\n";
        up_arr = other.up_arr;
        down_arr = other.down_arr;
        L = other.L;

        return *this;
    }
};

deque<int> up_arr, down_arr;

void input()
{
    for (int i = 0; i < 4; i++)
    {
        int t;
        cin >> t;
        up_arr.push_back(t);
    }

    for (int i = 3; i >= 0; i--)
    {
        int t;
        cin >> t;
        down_arr.push_front(t);
    }
}

int main()
{
    input();

    deque<Info> dq;
    deque<int> a = {1, 2, 3, 4};
    deque<int> b = {8, 7, 6, 5};
    dq.push_back({a, b, 0});

    while (!dq.empty())
    {
        deque<int> cur_up = dq.front().up_arr;
        deque<int> cur_down = dq.front().down_arr;
        int cur_L = dq.front().L;
        dq.pop_front();

        Info cur = {cur_up, cur_down, cur_L};

        if (cur.up_arr == up_arr && cur.down_arr == down_arr)
        {
            std::cout << cur.L;
            break;
        }

        Info ncur;
        ncur = cur;
        ncur.L = cur.L + 1;
         
        dq.push_back(ncur);

        ncur = cur;
        ncur.L = cur.L + 1;
        fB(ncur.up_arr, ncur.down_arr);
        dq.push_back(ncur);

        ncur = cur;
        ncur.L = cur.L + 1;
        fC(ncur.up_arr, ncur.down_arr);
        dq.push_back(ncur);

        ncur = cur;
        ncur.L = cur.L + 1;
        fD(ncur.up_arr, ncur.down_arr);
        dq.push_back(ncur);
    }
}