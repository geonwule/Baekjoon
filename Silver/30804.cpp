#include <iostream>
#include <vector>
#include <unordered_set> //unordered_set
#include <cstring> //memset

using namespace std;

#define FRUITS_KINDS 9 // 1 ~ 9
#define MAX 200000     // num of fruits MAX

int solution4(const int N, const vector<int> &v)
{
    int answer = 0;

    vector<int>::const_iterator left, right;
    left = right = v.begin();

    int fruits[FRUITS_KINDS + 1];
    memset(fruits, 0, sizeof(fruits));

    int cnt = 0;
    unordered_set<int> cur_fruits;
    while(right != v.end())
    {
        if (fruits[*right] == 0) //first contact
        {
            cur_fruits.insert(*right);
        }
        fruits[*right]++;
        cnt++;

        while (cur_fruits.size() > 2) // if over 2 kinds
        {
            fruits[*left]--;
            if (fruits[*left] == 0)
            {
                cur_fruits.erase(*left);
            }
            cnt--;
            left++;
        }
        answer = max(answer, cnt);
        right++;
    }

    return answer;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int &e : v)
        cin >> e;

    cout << solution4(N, v);
    return 0;
}