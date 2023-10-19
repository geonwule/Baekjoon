#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define MAX 100001

/*
std::ios_base :: sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
-> C++의 입출력 속도를 증가시킨다..
또한 그떄그떄 답을 출력하는거보다 벡터등에 한번에 모아놨다가 마지막에 출력하는게 속도를 더 증가시킨다.
*/
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;
    int v[MAX];
    int idx = 1;
    // std::vector<int> ret;
    // v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (tmp == 0)
        {
            if (idx == 1)
                std::cout << "0\n";
            else
            {
                std::cout << v[1] << "\n";
                // ret.push_back(v[1]);
                idx--;
                v[1] = v[idx]; // root replace to tail
                if (idx <= 2) // empty , only one
                    continue;
                // v.erase(v.end() - 1); // tail cut
                int cur = 1;
                while (1)
                {
                    int child1 = cur * 2, child2 = cur * 2 + 1;
                    int min = cur;
                    if (child1 < idx && v[child1] < v[min])
                        min = child1;
                    if (child2 < idx && v[child2] < v[min])
                        min = child2;
                    if (min != cur)
                    {
                        swap(v[cur], v[min]);
                        cur = min;
                    }
                    else
                        break ;
                }
            }
        }
        else
        {
            // v.push_back(tmp);
            v[idx] = tmp;
            int cur = idx;
            idx++;
            while (1)
            {
                if (cur == 1)
                    break;
                int par = cur / 2;
                if (par >= 1 && v[cur] < v[par])
                {
                    swap(v[cur], v[par]);
                    cur = par;
                }
                else break; // correct location
            }
        }
    }
}
