#include <iostream>
#include <string>

using namespace std;

void solution(const string &A, const string &B, const string &C, string &answer1, string &answer2)
{
    int int_a1 = stoi(A) + stoi(B) - stoi(C);
    answer1 = to_string(int_a1);

    answer2 = A + B;
    int int_a2 = stoi(answer2) - stoi(C);
    answer2 = to_string(int_a2);
}

int main()
{
    string A, B, C;
    std::getline(cin, A);
    std::getline(cin, B);
    std::getline(cin, C);

    string answer1, answer2;
    solution(A, B, C, answer1, answer2);

    cout << answer1 << '\n' << answer2 << '\n';
    return 0;
}