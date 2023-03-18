#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_ch
{
    int num;    //5457
    int len;    //4
    char str[10];   //"5457"
}   t_ch;
typedef struct s_ab
{
    int n;  //3
    char str[10];   // 6 7 8 = abnormal -> ab.str[6] = 0, ab.str[7] = 0, ab.str[8] = 0
}   t_ab;

t_ch    ch;
t_ab    ab;

void ab_init(void)
{
    for (int i = 0; i < 10; i++)
    {
        ab.str[i] = '1';
    }
    int t;
    for (int i = 0; i < ab.n; i++)
    {
        scanf("%d", &t);
        ab.str[t] = '0';
    }
}

void    input(void)
{
    scanf("%s %d", ch.str, &ab.n);
    ab_init();
    ch.num = atoi(ch.str);
    ch.len = (int)strlen(ch.str);
}

int compare(int a, int b)
{
    return (a < b ? a : b);
}

int abs_mi(int a, int b)
{
    return (a - b > 0 ? a-b : b-a);
}

int digit(int n)
{
    if (n == 0)
        return (1);
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return (cnt);
}

#define false 1
#define true 0

int broken_button(int but)
{
   int but_digit = digit(but);
   for (int i = 0; i < but_digit; i++)
   {
       if (ab.str[but % 10] == '0')
            return (false);
        but /= 10;
   }
   return (true);
}

int main()
{
    int now_num = 100;
    input();
    int ret = abs_mi(ch.num, now_num), temp;
    for (int i = 0; i <= 1000001; i++)
    {
        if (broken_button(i))
            continue ;
        temp = digit(i) + abs_mi(i, ch.num);
        ret = compare(ret, temp);
    }
    printf("%d\n", ret);
}