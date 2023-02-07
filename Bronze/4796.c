#include <stdio.h>

int main()
{
    int l, p, v;
    int cas = 0;
    int ret[100000] = {0 ,};

    while (1)
    {
        scanf("%d %d %d", &l,&p,&v);
        if (l == 0 && p == 0 && v == 0)
            break;
        ret[cas] = ((v / p) * l);
        if ((v % p) <= l)
            ret[cas] += v % p;
        else
            ret[cas] += l;
        cas++;
    }

    for (int i = 0; i < cas; i++)
    {
        printf("Case %d: %d\n", i + 1, ret[i]);
    }
}