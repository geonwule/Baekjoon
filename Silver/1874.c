#include <stdio.h>
#include <stdlib.h>

// void    arr_init(int *stack, int n)
// {
//     for (int i = 0; i < n; i++)
//         stack[i] = i + 1;
// }

void    arr_init(int *stack, int n)
{
    for (int i = 0; i < n; i++)
        stack[i] = 0;
}

int main()
{
    int n;
    scanf ("%d", &n);
    int box[n];
    int stack[n]; // 0 init
    char ret[(n * 2) + 1];
    ret[n * 2] = '\0';
    arr_init(stack, n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &box[i]);
    }
    int i = 0;
    int j = 1;
    int k = 0;
    int q = 0;
    while (i < n)
    {
        if (j == box[i])
        {
            ret[q] = '+';
            ret[q+1] = '-';
            q += 2;
            i++;
            j++;
        }
        else if (j < box[i])
        {
            ret[q] = '+';
            q++;
            stack[k] = j;
            k++;
            j++;
        }
        else if (j > box[i])
        {
            if (stack[k-1] != box[i])
            {
                printf("NO\n");
                return (0);
            }
            ret[q] = '-';
            i++;
            k--;
            q++;
        }
    }
    for (int i = 0; ret[i] != '\0'; i++)
        printf("%c\n", ret[i]);
}