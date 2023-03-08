#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int abnormal(char a, char *ab, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (ab[i] == a)
            return (1);
    }
    return (0);
}

char remote_push(char a, char *ab, int num)
{
    int i, j = 1;

    i = a - '0';
    if (!abnormal(a, ab, num))
        return (a);
    while (1)
    {
        if (i + j < 10)
        {
            if (!abnormal(i + j + '0', ab, num))
                return (i + j + '0');
        }
        if (i - j >= 0)
        {
            if (!abnormal(i - j + '0', ab, num))
                return (i - j + '0');
        }
        j++;
    }
}

void ab_init(char *ab, int num)
{
    int t;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &t);
        ab[i] = t + '0';
    }
}

int main()
{
    int num, ch_num, ch_len, cnt = 0;
    char ch[10], ab[10], remote[10] = {
                             0,
                         };
    scanf("%s %d", ch, &num);
    ab_init(ab, num);
    ch_num = atoi(ch);
    ch_len = (int)strlen(ch);
    char t;
    for (int i = 0; i < ch_len; i++)
    {
        remote[i] = remote_push(ch[i], ab, num);
    }
    int remote_num = atoi(remote);
    int j = 0;
    while (remote[1] != '\0' && remote[j] == '0')
        j++;
    while (remote[j] != '\0')
    {
        cnt++;
        j++;
    }
    while (remote_num != ch_num)
    {
        if (ch_num > remote_num) // +
            remote_num++;
        else // -
            remote_num--;
        cnt++;
    }
    printf("%d\n", cnt);
}