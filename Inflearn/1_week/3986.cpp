#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> v)
{
    int answer = 0;

    return answer;
}

/*문제가 이해가 안됌.

평석이는 단어 위로 아치형 곡선을 그어 같은 글자끼리(A는 A끼리, B는 B끼리) 쌍을 짓기로 하였다. 
만약 선끼리 교차하지 않으면서 각 글자를 정확히 한 개의 다른 위치에 있는 같은 글자와 짝 지을수 있다면, 
그 단어는 '좋은 단어'이다. 평석이가 '좋은 단어' 개수를 세는 것을 도와주자.
*/
int main()
{
    int N;
    cin >> N;
    vector<string> v(N);
    for (string &s : v)
        cin >> s;
    
    cout << solution(v);

    return 0;
}