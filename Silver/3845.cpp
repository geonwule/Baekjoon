#include <iostream>
#include <vector>

using namespace std;

string solution(const int nx, const int ny, const float w, const vector<float>& arrX, const vector<float>& arrY)
{
    const float width = 100.f, height = 75.f;
    return "YES";
}

int main()
{
    vector<string> answer;
    while (true)
    {
        int nx, ny;
        float w;
        cin >> nx >> ny >> w;
        if (nx == 0 && ny == 0 && w == 0.0)
            break;
        vector<float> arrX(ny), arrY(nx);
        for (float &y : arrY)
            cin >> y;
        for (float &x : arrX)
            cin >> x;
        answer.push_back(solution(nx, ny, w, arrX, arrY));
    }

    for (string &s : answer)
        cout << s << endl;
    return 0;
}