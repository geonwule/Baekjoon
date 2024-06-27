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

string changeTimeStandard(const size_t t)
{
    string ts;
    ts += to_string(t / 60).size() == 2 ? to_string(t / 60) : "0" + to_string(t / 60);
    ts += ':';
    ts += to_string(t % 60).size() == 2 ? to_string(t % 60) : "0" + to_string(t % 60);
    return ts;
}

size_t changeTimeToSeconds(const string &s)
{
    size_t pos = s.find(':');
    string mm = s.substr(0, pos);
    string ss = s.substr(pos + 1);

    return stoi(mm) * 60 + stoi(ss);
}

vector<string> solve2(vector<pair<int, string>> goals)
{
    vector<string> answer(2);
    size_t wt[2] = {0, 0}; // win time

    int win_team = 0, win_cnt = 0;
    size_t gtime = 0;
    for (const auto goal : goals)
    {
        int team = goal.first;
        string time = goal.second;
        size_t rtime = changeTimeToSeconds(time);

        // 한 팀이 앞서는 최초시간
        if (win_cnt == 0)
        {
            win_team = team;
            win_cnt++;
            gtime = rtime;
            continue;
        }

        // 어떤 팀이 이미 앞서고 있을 때

        // 같은팀이 또 점수 낸경우
        if (win_team == team)
        {
            win_cnt++;
        }
        // 다른팀이 점수를 낸경우
        else
        {
            win_cnt--;
            // 동점이 된경우
            if (win_cnt == 0)
            {
                wt[win_team - 1] += rtime - gtime;
                win_team = 0; // 이긴팀 초기화
            }
        }
    }

    // 경기 끝났을때 이긴팀이 있을 경우
    if(win_team)
    {
        size_t rtime = 60 * 48;
        wt[win_team - 1] += rtime - gtime;
    } 

    for (int i = 0; i < 2; i++)
        answer[i] = changeTimeStandard(wt[i]);
    return answer;
}

string changeTimeStandard2(const size_t t)
{
    string ts;
    ts += to_string(t / 60).size() == 2 ? to_string(t / 60) : "0" + to_string(t / 60);
    ts += ':';
    ts += to_string(t % 60).size() == 2 ? to_string(t % 60) : "0" + to_string(t % 60);
    return ts;
}

size_t changeTimeToSeconds2(const string &s)
{
    size_t pos = s.find(':');
    string mm = s.substr(0, pos);
    string ss = s.substr(pos + 1);

    return stoi(mm) * 60 + stoi(ss);
}

int A = 0, B = 0, Asum = 0, Bsum = 0;
string prev2;

void    go(int &sum, const string &time)
{
    sum += changeTimeToSeconds2(time) - changeTimeToSeconds2(prev2);
}

vector<string> solve3(vector<pair<int, string>> goals)
{
    vector<string> answer;
    for (int i = 0; i < goals.size(); i++)
    {
        const int &team = goals[i].first;
        const string &time = goals[i].second;
        if (A > B) go(Asum, time);
        else if (B > A) go(Bsum, time);

        team == 1 ? A++ : B++;
        prev2 = time;
    }

    if (A > B) go(Asum, "48:00");
    else if (B > A) go(Bsum, "48:00");

    answer.push_back(changeTimeStandard2(Asum));
    answer.push_back(changeTimeStandard2(Bsum));
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

    // vector<string> answer = solve(goals);
    // vector<string> answer = solve2(goals);
    vector<string> answer = solve3(goals);
    for (const string &s : answer)
        cout << s << '\n';

    return 0;
}