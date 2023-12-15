#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;

    string answer = input; // 초기화

    for (int i = 1; i < input.length() - 1; ++i) {
        for (int j = i + 1; j < input.length(); ++j) {
            string first_part = input.substr(0, i);
            string second_part = input.substr(i, j - i);
            string third_part = input.substr(j);

            reverse(first_part.begin(), first_part.end());
            reverse(second_part.begin(), second_part.end());
            reverse(third_part.begin(), third_part.end());

            string combined = first_part + second_part + third_part;

            if (combined < answer) {
                answer = combined;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
