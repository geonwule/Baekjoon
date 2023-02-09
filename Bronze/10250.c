#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ret_set(int y, int x, int n)// x = 12 y = 6 n = 10 -> 402
{
    int ret;
    int cnt = 0, bk = 0;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cnt++;
            if (cnt == n)
            {
                x = i + 1;
                y = j + 1;
                bk = 1;
                break ;
            }
        }
        if (bk)
            break ;
    }
    ret = x + (y * 100);
    return (ret);
}

int main()
{
    int t, h, w, n;
    scanf("%d", &t);
    int ret[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &h,&w,&n);
        ret[i] = ret_set(h, w, n);
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", ret[i]);
}