#include <stdio.h>

typedef struct s_lst
{
    char *name;
    int good;
} t_lst;

void init_set(t_lst *adrian, t_lst *bruno, t_lst *goran)
{
    adrian->name = "ABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABC";
    adrian->good = 0;
    bruno->name = "BABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABC";
    bruno->good = 0;
    goran->name = "CCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABB";
    goran->good = 0;
}

void    ret_print(int a, int b, int g)
{
    int max = a;
    if (b > max)
    {
        max = b;
        if (g > max)
            max = g;
    }
    else if (g > max)
        max = g;
    printf("%d\n", max);
    if (max == a)
        printf("Adrian\n");
    if (max == b)
        printf("Bruno\n");
    if (max == g)
        printf("Goran\n");
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

  // if (a == b && b == g)
    // {
    //     printf("%d\nAdrian\nBruno\nGoran\n", a);
    //     return ;
    // }
    // if (a == b)
    // {
    //     if (a > g)
    //         printf("%d\nAdran\nBruno\n", a);
    //     else
    //         printf("%d\nGoran\n", g);
    //     return ;
    // }
    // else if (a == g)
    // {
    //     if (a > b)
    //         printf("%d\nAdrian\nGoran\n", a);
    //     else
    //         printf("%d\nBruno\n", b);
    //     return ;
    // }
    // else if (b == g)
    // {
    //     if (b > a)
    //         printf("%d\nBruno\nGoran\n", b);
    //     else
    //         printf("%d\nAdrian\n", a);
    //     return ;
    // }
    // int max = a;
    // if (b > max)
    // {
    //     max = b;
    //     if (g > max)
    //     {
    //         printf("%d\nGoran\n", g);
    //     }
    //     else
    //         printf("%d\nBruno\n", b);
    // }
    // else if (g > max)
    //     printf("%d\nGoran\n", g);
    // else
    //     printf("%d\nAdrian\n", a);