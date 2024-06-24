#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> visit_kind, visit_name, visited;

void combi(map<string, vector<string>>& mpv, int &cnt, vector<string> b = vector<string>())
{
    if (!b.empty())
    {
        sort(b.begin(), b.end());
        string tmp;
        for(auto& e : b)
        {
            tmp += e + ',';
        }
        if (!visited.count(tmp))
        {
            cnt++;
            visited.insert(tmp);
        }
    }
    
    for (auto mit = mpv.begin(); mit != mpv.end(); mit++)
    {
        vector<string> &v = mit->second;
        for (auto vit = v.begin(); vit != v.end(); vit++)
        {
            if (!visit_kind.count(mit->first) && !visit_name.count(*vit))
            {
                visit_kind.insert(mit->first);
                visit_name.insert(*vit);
                b.push_back(*vit);
                combi(mpv, cnt, b);
                b.pop_back();
                visit_name.erase(*vit);
                visit_kind.erase(mit->first);
            }
        }
    }
}

void solution(map<string, vector<string>>& mpv, vector<int> &answer)
{
    int cnt = 0;
    visited.clear();
    combi(mpv, cnt);
    answer.push_back(cnt);
}

int main()
{
    int T;
    cin >> T;
    
    vector<int> answer;

    while (T--)
    {
        int N;
        cin >> N;
        map<string, vector<string>> mpv;
        while (N--)
        {
            string name, kind;
            cin >> name >> kind;
            if (mpv.find(kind) == mpv.end())
            {
                mpv[kind] = vector<string>(1, name);
            }
            else
            {
                mpv[kind].push_back(name);
            }
        }
        solution(mpv, answer);
    }

    for (const auto& i : answer)
        cout << i << '\n';
    return 0;
}
//test
    // cout << "-----\n";
    // for (auto it = mpv.begin(); it != mpv.end(); it++)
    // {
    //     cout << it->first << ": ";
    //     vector<string> &v = it->second;
    //     for (auto it2 = v.begin(); it2 != v.end(); it2++)
    //         cout << *it2 << ' ';
    //     cout << '\n';
    // }