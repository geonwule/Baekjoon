#include <iostream>
#include <string>
#include <vector>

using namespace std;

void input(vector<int> &n1, vector<int> &n2);
void print_vector(const vector<int> &v);

/*example
n1 = 1234
n2 = 31

    1234
    x 31
    -----
    1   2   3   4
3   6   9(1)2

*/

namespace Util
{
    template <typename T>
    T &max(const T &a, const T &b)
    {
        return a > b ? a : b;
    }
}

void carry_on(vector<int> &result)
{
    int carry = 0;
    for (size_t i = 0; i < result.size(); i++)
    {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
}

vector<int> &multiple(const vector<int> &n1, const vector<int> &n2)
{
    static vector<int> result;
    size_t n1_len = n1.size();
    size_t n2_len = n2.size();
    size_t result_len = n1_len + n2_len;

    result.resize(result_len, 0);
    for (size_t i = 0; i < n1_len; i++)
    {
        int e1 = n1[i];
        for (size_t j = 0; j < n2_len; j++)
        {
            int e2 = n2[j];
            result[j + i] += e1 * e2;
        }
    }

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    vector<int> a, b;
    input(a, b);
    // print_vector(a);
    // print_vector(b);
    vector<int> &res = multiple(a, b);
    carry_on(res);
    print_vector(res);
    return 0;
}

void print_vector(const vector<int> &v)
{
    bool skip_zero = true;
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        if (skip_zero && *it == 0)
            continue;
        else
            skip_zero = false;
        cout << *it;
    }
    cout << '\n';
}

void change_string_to_vector(vector<int> &v, const string &s)
{
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        v.push_back(*it - '0');
    }
}

void input(vector<int> &n1, vector<int> &n2)
{
    string a, b;
    cin >> a >> b;
    change_string_to_vector(n1, a);
    change_string_to_vector(n2, b);
}