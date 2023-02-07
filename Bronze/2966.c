#include <stdio.h>

typedef struct s_lst
{
    char *name;
    int good;
} t_lst;

void init_set(t_lst *adrian, t_lst *bruno, t_lst *goran)
{
    adrian->name = "ABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABC";
    adrian->good = 0;
    bruno->name = "BABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABC";
    bruno->good = 0;
    goran->name = "CCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABB";
    goran->good = 0;
}

void    ret_print(int a, int b, int g)
{
    if (a == b && b == g)
    {
        printf("%d\nAdrian\nBruno\nGoran\n", a);
        return ;
    }
    int max;

    if (a == b)
    {
        if (a > g)
        {
            printf("%d\nAdran\nBruno\n", a);
            return ;
        }
    }
    else if (a == g)
    {
        if (a > b)
        {
            printf("%d\nAdrian\nGoran\n", a);
            return ;
        }
    }
    else if (b == g)
    {
        if (b > a)
        {
            printf("%d\nBruno\nGoran\n", b);
            return ;
        }
    }
    max = a;
    if (b > max)
    {
        max = b;
        if (g > max)
        {
            printf("%d\nGoran\n", g);
        }
        else
            printf("%d\nBruno\n", b);
    }
    else if (g > max)
    {
        max = g;
    }
    else
        printf("%d\nAdrian\n", a);
}

int main()
{
    int n;
    scanf("%d", &n);
    char box[n + 1];
    scanf("%s", box);

    t_lst adrian, bruno, goran;
    init_set(&adrian, &bruno, &goran);
    for (int i = 0; i < n; i++)
    {
        if (box[i] == adrian.name[i])
            adrian.good += 1;
        if (box[i] == bruno.name[i])
            bruno.good += 1;
        if (box[i] == goran.name[i])
            goran.good += 1;
    }
    ret_print(adrian.good, bruno.good, goran.good);
}