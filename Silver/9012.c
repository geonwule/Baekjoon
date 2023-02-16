#include <stdio.h>
#include <string.h>

int vps_check(char *s, int s_len)
{
    int flag=0;
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] == '(')
            flag++;
        else if (s[i] == ')')
            flag--;
        if (flag < 0)
            return (0);
    }
    if (flag == 0)
        return (1);
    return (0);
}

int main()
{
    int n, str_len;
    char str[100];
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        str_len = strlen(str);
        if (str_len % 2 != 0)
        {
            printf("NO\n");
            continue ;
        }
        if (vps_check(str, str_len))
            printf("YES\n");
        else
            printf("NO\n");
    }
}