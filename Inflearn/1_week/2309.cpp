#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backTracking(int lev, int sum, vector<int> v, vector<int> visit, vector<int> &answer, const vector<int>& arrs)
{
    if (lev == 7 || sum > 100)
    {
        if (sum == 100)
            answer = v;
        return;
    }

    for (int i = 0; i < arrs.size(); i++)
    {
        if (!visit[i])
        {
            visit[i] = 1;
            v.push_back(arrs[i]);
            backTracking(lev + 1, sum + arrs[i], v, visit, answer, arrs);
            visit[i] = 0;
            v.erase(v.end() - 1);
        }
    }
}

vector<int> solution2(vector<int> arrs)
{
    vector<int> answer;
    backTracking(0, 0, vector<int>(), vector<int>(9, 0), answer, arrs);
    sort(answer.begin(), answer.end());
    return answer;
}

vector<int> solution(vector<int> arrs)
{
    // sort(arrs.begin(), arrs.end());
    int sum = 0;
    for (int &arr : arrs)
        sum += arr;

    int except1, except2;

    for (int i = 0; i < arrs.size(); i++)
    {
        bool find = false;
        for (int j = i + 1; j < arrs.size(); j++)
        {
            if (sum - arrs[i] - arrs[j] == 100)
            {
                except1 = i;
                except2 = j;
                find = true;
                break;
            }
        }
    }
    
    vector<int> answer;
    for (int i = 0; i < arrs.size(); i++)
    {
        if (i != except1 && i != except2)
            answer.push_back(arrs[i]);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> arrs(9);
    for (int &arr : arrs)
        cin >> arr;
    
    // const vector<int> answer = solution(arrs);
    const vector<int> answer = solution2(arrs);
    for (const int &e : answer)
        cout << e << '\n';
}