#include <stdio.h>
#define AS 1
#define DS 2
#define MIX 3

void    print_ret(int i)
{
    if (i == AS)
        printf("ascending\n");
    if (i == DS)
        printf("descending\n");
    if (i == MIX)
        printf("mixed\n");
}

int main()
{
    int a, ret;
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &a);
        if (i == 0 && a == 1)
            ret = AS;
        else if (i == 0 && a == 8)
            ret = DS;
        else if (i == 0)
        {
            print_ret(MIX);
            return (0);
        }
        if (ret == AS && a != i + 1)
            ret = MIX;
        else if (ret == DS && a != (8 - i))
            ret = MIX;    
    }
    print_ret(ret);
}