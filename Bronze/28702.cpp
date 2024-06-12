#include <iostream>
#include <stdexcept>

const std::string &to_FizzBuzz(int answer)
{
    static std::string str;
    if (answer % 3 == 0 && answer % 5 == 0)
        str = "FizzBuzz";
    else if (answer % 3 == 0)
        str = "Fizz";
    else if (answer % 5 == 0)
        str = "Buzz";
    else
        str = std::to_string(answer);
    
    // std::cout << "ok\n";
    return (str);
}

int main()
{
    std::string str[3];
    for (int i = 0; i < 3; i++)
        std::getline(std::cin, str[i]);
    
    int value, idx;
    value = idx = 0;

    for (int i = 0; i < 3; i++)
    {
        try{
            // std::cout << stoi(str[i]) << '\n';
            value = stoi(str[i]);
            idx = i;
            break;
        }
        catch (std::exception &e)
        {
            // std::cout << e.what() << '\n';
        }
    }

    int answer = value + (3 - idx);
    // std::cout << answer;

    const std::string &ch = to_FizzBuzz(answer);
    std::cout << ch << '\n';
    return 0;
}