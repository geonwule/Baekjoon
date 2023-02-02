#include <stdio.h>

int main()
{
    int ret = 0;
    int temp;
    int conti = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &temp);
        if (conti == 1)
            continue ;
        if (ret + temp <= 100)
            ret += temp;
        else if (ret + temp - 100 <= 100 - ret)
            ret += temp;
        else
            conti = 1;
    }
    printf("%d\n", ret);
}