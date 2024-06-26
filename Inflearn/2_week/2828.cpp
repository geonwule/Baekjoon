#include <iostream>
#include <vector>

using namespace std;

int solution(int screen_width, int bucket_size, int J, vector<int>& v)
{
    int answer = 0;
    int pos = 1;
    for (const int apple_pos : v)
    {
        if (apple_pos >= pos && apple_pos <= pos + bucket_size - 1)
            continue;
        
        if (apple_pos < pos)
        {
            answer += pos - apple_pos;
            pos = apple_pos;
        }
        else // apple_pos > pos + bucket_size - 1
        {
            answer += apple_pos - (pos + bucket_size - 1);
            pos += apple_pos - (pos + bucket_size - 1);
        }
    }
    return answer;
}

int main()
{
    int N, M, J;
    cin >> N >> M >> J;
    vector<int> v(J);
    for (int &i : v)
        cin >> i;
    
    cout << solution(N, M, J, v);

    return 0;
}

/*

1   3   5
0 0 0 0 0

+ +
      + +
    + +  

*/
