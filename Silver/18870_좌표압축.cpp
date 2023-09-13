#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<int> arr;

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    std::vector<int> back = arr;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i = 0; i < n; i++)
    {
        int target = back[i];
        std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), target);
        std::cout << it - arr.begin();
        if (i + 1 != n)
            std::cout << " ";
    }
}