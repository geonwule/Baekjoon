#include <iostream>
#include <bitset>

using namespace std;
#define Max 101

bool b_switch[Max];
size_t _size;

void input_switch()
{
    for (size_t i = 1; i <= _size; i++)
        cin >> b_switch[i];
}

int main()
{
    cin >> _size;
    input_switch();
    
    size_t numStudents;
    cin >> numStudents;
    for (size_t i = 0; i < numStudents; i++)
    {
        int sex, target;
        cin >> sex >> target;
        if (sex == 1) // man
        {
            for (int j = 1; j * target <= _size; j++)
            {
                b_switch[j * target] = !b_switch[j * target];
            }
        }
        else // woman
        {
            for (int j = 0; (target - j > 0 && target + j <= _size) && b_switch[target + j] == b_switch[target - j]; j++)
            {
                if (j == 0) // middle
                {
                    b_switch[target] = !b_switch[target];
                }
                else // side
                {
                    b_switch[target - j] = !b_switch[target - j];
                    b_switch[target + j] = !b_switch[target + j];
                }
            }
        }
    }
    for (size_t i = 1; i <= _size; i++)
    {
        cout << (b_switch[i]) << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
}