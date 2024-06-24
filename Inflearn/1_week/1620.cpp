#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(map<int, string>& is_map, map<string, int>& si_map, const vector<string>& problems)
{
    vector<string> answer;
    for (const auto& problem : problems)
    {
        stringstream ss(problem);
        int num;
        ss >> num;
        if (ss.eof())
        {
            answer.push_back(is_map[num]);
        }
        else
        {
            answer.push_back(to_string(si_map[problem]));
        }
    }

    return answer;
}

vector<string> solution2(map<int, string>& is_map, map<string, int>& si_map, const vector<string>& problems)
{
    vector<string> answer;
    for (const auto& problem : problems)
    {
        try {
            int num = stoi(problem);
            answer.push_back(is_map[num]);
        }
        catch (exception &e){
            answer.push_back(to_string(si_map[problem]));
        }
    }

    return answer;
}

#include <cstdlib>
vector<string> solution3(map<int, string>& is_map, map<string, int>& si_map, const vector<string>& problems)
{
    vector<string> answer;
    for (const auto& problem : problems)
    {
        int num = atoi(problem.c_str());
        if (num)
        {
            answer.push_back(is_map[num]);
        }
        else
        {
            answer.push_back(to_string(si_map[problem]));
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    map<int, string> is_map;
    map<string, int> si_map;
    for (int i = 1; i <= N; i++)
    {
        string name;
        cin >> name;
        is_map[i] = name;
        si_map[name] = i;
    }
    vector<string> problems(M);
    for (auto &problem : problems)
        cin >> problem;
    
    // vector<string> answer = solution(is_map, si_map, problems);
    // vector<string> answer = solution2(is_map, si_map, problems);
    vector<string> answer = solution3(is_map, si_map, problems);

    for (const auto& e : answer)
        cout << e << '\n';

    return 0;
}