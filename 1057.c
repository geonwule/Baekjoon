#include <stdio.h>
#include <stdlib.h>

int kim_lim_1(int kim, int lim)
{
    int bbagi = kim - lim;
    int small = kim;

    if (bbagi < 0)
        bbagi *= -1;
    if (kim > lim)
        small = lim;
    if (bbagi == 1 && small % 2 == 1)   //kim vs lim
        return (1);
    return(0);
}

void    round_ing(int *kim, int *lim)
{
    if (*kim % 2 == 1)
        *kim += 1;
    if (*lim % 2 == 1)
        *lim += 1;
    *kim /= 2;
    *lim /= 2;
}

int main()
{
    int round = 1;
    int n, kim, lim;

    scanf("%d %d %d", &n, &kim, &lim);

    while (round <= n)
    {
        if (kim_lim_1(kim, lim))
            break ;
        round_ing(&kim, &lim);
        round++;
    }
    if (round == n)
    {
        printf("-1\n");
        return (0);
    }
    printf("%d\n", round);
}