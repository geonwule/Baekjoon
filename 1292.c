#include <stdio.h>

void    soo_insert(int *soo)
{
    int i = 0;
    int j = 1;
    int cnt;
    while (i < 1000)
    {
        cnt = 0;
        while (i < 1000)
        {
            soo[i] = j;
            cnt++;
            if (cnt == j)
                break ;
            i++;
        }
        j++;
        i++;
    }
}

int main()
{
    int soo[1000];
    int a, b;
    int ret = 0;

    soo_insert(soo);
    scanf("%d %d", &a, &b);
    a--;
    b--;
    while (a <= b)
    {
        ret += soo[a];
        a++;
    }
    printf("%d\n", ret);
}