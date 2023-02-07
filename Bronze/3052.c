#include <stdio.h>

int main()
{
    int n[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &n[i]);
        n[i] = n[i] % 42;
    }
    int ret = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            ret++;
            continue ;
        }
        int k = 1;
        while (i - k >= 0 && n[i - k] != n[i])
        {
            if (i - k == 0)
                ret++;
            k++;
        }
    }
    printf("%d\n", ret);
}