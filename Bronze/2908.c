#include <stdio.h>

int main()
{
    int n = 1;
    char a[4], b[4];
    scanf("%s", a);
    scanf("%s", b);
    for (int i = 2; i >= 0; i--)
    {
        if (a[i] > b[i])
        {
            n = 1;
            break;
        }
        else if (a[i] < b[i])
        {
            n = 2;
            break;
        }
    }
    for (int i = 2; i >= 0; i--)
    {
        if (n == 1)
        {
            printf("%c", a[i]);
        }
        else
        {
            printf("%c", b[i]);
        }
    }
    printf("\n");
}