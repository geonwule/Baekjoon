#include <stdio.h>
#include <stdlib.h>

void    arr_init(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
}

int main()
{
    int n;
    scanf ("%d", &n);
    int box[n];
    int arr[n];
    arr_init(arr, n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &box[i]);
    }
    int i = 0;
    int j = 1;
    int k = 0;
    while (i < n)
    {
        if (j < box[i])
        {
            printf("+\n");
            j++;
            arr[k] = j;
            k++;
        }
        else if (j == box[i])
        {
            printf("+\n-\n");
            i++;
            j++;
            k--;
        }
        else if (j > box[i])
        {
            while (arr[k] == box[i])
            {
                printf("-\n");
                k--;
            }
        }
    }
}