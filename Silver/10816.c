#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void count_sang(int *box, int L, int R, int key)
{
    int ret = 0, left = L, right = R;
    int pivot;
    while (left <= right)
    {
        pivot = (left + right) / 2;
        if (box[pivot] == key)
        {
            for (int i = 1; pivot-i >= left && box[pivot-i] == key; i++)
                pivot -= 1;
            for (int i = 0; pivot+i <= right && box[pivot+i] == key; i++)
                ret++;
            printf("%d", ret);
            return ;
        }
        else if (key > box[pivot])
            left = pivot + 1;
        else if (key < box[pivot])
            right = pivot - 1;
    }
    printf("0");
}

int main()
{
    int n, m, temp;
    scanf("%d", &n);
    int box[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &box[i]);
    }
    qsort(box, n, sizeof(int), compare);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        count_sang(box, 0, n-1, temp);
        if (i+1 == m)   // input end
            printf("\n");
        else
            printf(" ");
    }
}

// void count_sang(int *box, int L, int R, int temp)
// {
//     int ret = 0, left = L, right = R, i;
//     int pivot = (L + R) / 2;
//     // if (pivot+1 < R && temp == box[pivot+1])
//     //     pivot += 1;
//     // else if (pivot-1 >= L && temp == box[pivot-1])
//     //     pivot -= 1;
//     if (temp == box[pivot])
//     {
//         i = 1;
//         while (pivot - i >= L && temp == box[pivot -i])
//             i++;
//         pivot -= (i - 1);
//         ret++;
//         for (int i = 1; pivot + i <= R && temp == box[pivot + i]; i++)
//             ret++;
//         printf("%d", ret);
//         return ;
//     }
//     if (L+1 == R)
//     {
//         printf("%d", ret);
//         return ;
//     }
//     if (temp > box[pivot])
//     {
//         count_sang(box, pivot, R, temp);
//     }
//     else if (temp < box[pivot])
//     {
//         count_sang(box, L, pivot, temp);
//     }
// }