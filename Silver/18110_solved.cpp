#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int>    arr;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());
    long jersa = round((double)n * 0.15);
    long ret = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < jersa || i >= n - jersa)
            continue ;
        ret += arr[i];
        cnt++;
    }
    if (cnt == 0)
    {
        std::cout << 0;
        return (0);
    }
    ret = round((double)ret / cnt);
    std::cout << ret;
}