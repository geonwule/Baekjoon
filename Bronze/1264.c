#include <stdio.h>

int main()
{
    char    buf[256];
    int     cnt_box[10000];
    int     cnt;
    int     j = 0;
    while (1)
    {
        scanf("%s", buf);
        if (buf[0] == '#')
            break ;
        cnt = 0;
        for (int i = 0; buf[i] != '\0'; i++)
        {
            char c = buf[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                cnt++;
        }
        cnt_box[j] = cnt;
        j++;
    }
    for (int k = 0; k < j; k++)
        printf("%d\n", cnt_box[k]);
}