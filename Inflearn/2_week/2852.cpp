#include <iostream>
#include <vector>

using namespace std;

vector<string> solve(vector<pair<int, string>> goals)
{
    vector<string> answer(2);
    size_t time_sum[3] = {0, 0, 0};

    pair<int, int> winner_score = {0, 0};
    size_t gsecs = 0;
    for (const auto p : goals)
    {
        int team = p.first;
        string time = p.second;

        if (winner_score.second) // 점수가 한팀이 이미 앞서고 있는 경우
        {
            if (winner_score.first == team)
                winner_score.second++;
            else
                winner_score.second--;
        }
        else
        {
            winner_score.second = 1;
        }

        size_t pos = time.find(':');
        string mm = time.substr(0, pos);
        string ss = time.substr(pos + 1);
        size_t cur_secs = stoi(mm) * 60 + stoi(ss);

        //어떤팀이 앞서기 시작한 경우
        if (winner_score.first == 0 && winner_score.second)
        {
            winner_score.first = team;
            gsecs = cur_secs;
        }
        //동점으로 바뀌어 시간을 측정해야 하는 경우
        else if (winner_score.first && winner_score.second == 0)
        {
            time_sum[winner_score.first] += cur_secs - gsecs;
            gsecs = 0;
            winner_score.first = 0;
        }
    }

    if (winner_score.first)
    {
        size_t cur_secs = 48 * 60;
        time_sum[winner_score.first] += cur_secs - gsecs;
    }

    answer[0] += to_string(time_sum[1] / 60).size() == 2 ? to_string(time_sum[1] / 60) : "0" + to_string(time_sum[1] / 60);
    answer[0] += ":";
    answer[0] += to_string(time_sum[1] % 60).size() == 2 ? to_string(time_sum[1] % 60) : "0" + to_string(time_sum[1] % 60);

    answer[1] += to_string(time_sum[2] / 60).size() == 2 ? to_string(time_sum[2] / 60) : "0" + to_string(time_sum[2] / 60);
    answer[1] += ":";
    answer[1] += to_string(time_sum[2] % 60).size() == 2 ? to_string(time_sum[2] % 60) : "0" + to_string(time_sum[2] % 60);

    return answer;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, string>> goals;
    while (N--)
    {
        int num;
        string time;
        cin >> num >> time;
        goals.push_back({num, time});
    }

    vector<string> answer = solve(goals);
    for (const string &s : answer)
        cout << s << '\n';

    return 0;
}