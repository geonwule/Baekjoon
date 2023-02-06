#include <stdio.h>

int prime_check(int in)
{
    if (in == 1 || in == 2 || in == 3 || in == 5)
        return (1);
    for (int i = 2; i <= in / 2 + 1; i++)
    {
        if (in % i == 0)
            return (0);
    }
    return (1);
}

int c_to_i(char *in)
{
    int ret = 0;
    int c;

    for (int i = 0; in[i] != '\0'; i++)
    {
        if (in[i] >= 'a' && in[i] <= 'z')
            ret += in[i] - 96;
        else if (in[i] >= 'A' && in[i] <= 'Z')
            ret += in[i] - 38;
    }
    return (ret);
}

int main()
{
    char input[100];

    scanf("%s", input);
    int i_input = c_to_i(input);

    if (prime_check(i_input))
        printf("It is a prime word.\n");
    else
        printf("It is not a prime word.\n");
}