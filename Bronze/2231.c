#include <stdio.h>

int digit_check(int n)
{
    int ret = 0;
    while (n)
    {
        ret++;
        n /= 10;
    }
    return (ret);
}

int digit_plus(int i)
{
    int ret = 0;

    while (i)
    {
        ret += i % 10;
        i /= 10;
    }
    return (ret);
}

int main()
{
    int n, n_len, sang = 1;
    scanf ("%d", &n);
    n_len = digit_check(n);
    for (int i = 1; i < n_len - 1; i++)
        sang *= 10;
    while (sang < n)
    {
        if (n == sang + digit_plus(sang))
        {
            printf("%d\n", sang);
            return (0);
        }
        sang++;
    }
    printf("0\n");
}