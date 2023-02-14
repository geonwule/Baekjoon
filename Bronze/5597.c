#include <stdio.h>

int main()
{
    int box[30];
    int a, b = 0, c = 0;
    for (int i = 0; i < 28; i++)
    {
        scanf("%d", &a);
        box[a-1] = -1;
    }
    for (int i = 0; i < 30; i++)
    {
        if (box[i] != -1)
        {
            if (c != 0)
                b = i + 1;
            else
                c = i + 1;
        }
    }
    if (c < b)
        printf("%d\n%d\n", c, b);
    else
        printf("%d\n%d\n", b, c);
}