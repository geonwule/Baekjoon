#include <stdio.h>
#include <stdlib.h>

void    ret_set(int *ret)
{
    for (int i = 0; i < 100; i++)
    {
        ret[i] = -1;
    }
}

int who_win(int *sol, int sol_num)
{
    int i = 0;
    int temp;
    int cnt;
    while (i < sol_num)
    {
        cnt = 1;
        temp = sol[i];
        for (int j = i + 1; j < sol_num; j++)
        {
            if (temp == sol[j])
                cnt++;
        }
        // printf("i = %d, temp = %d,  cnt = %d\n", i, temp,  cnt);
        if (cnt > sol_num / 2)
        {
            return (temp);
        }
        i++;
    }
    return (-2);    // SYJKGW
}

// void    print_ret(int *sol_group, int sol_num)
// {
//         printf("\n--sol_group---\n");
//         for (int q = 0; q < sol_num; q++)
//         {
//             printf("%d", sol_group[q]);
//         }
//         printf("\n");
// }

int main()
{
    int ddang;
    int ret[200];

    ret_set(ret);
    scanf("%d", &ddang);
    for(int i = 0; i < ddang; i++)
    {
        int sol_num;
        scanf("%d", &sol_num);

        int *sol_group;
        sol_group = (int *)calloc(100000, sizeof(int));
        for(int j = 0; j < sol_num; j++)
        {
            int sol;
            scanf("%d", &sol);
            sol_group[j] = sol;
        }
        ret[i] = who_win(sol_group, sol_num);
        free(sol_group);
    }
    // for (int i = 0; i < 4; i++)
    //     printf("%d\n", ret[i]);
    for (int k = 0; k < 200 && ret[k] != -1; k++)
    {
        if (ret[k] == -2)
            printf("SYJKGW\n");
        else
            printf("%d\n", ret[k]);
    }
}