#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int x;
    int y;
} t_list;

void x_qsort(t_list *box, int L, int R)
{
    int left = L, right = R, temp, pivot = box[(L + R) / 2].x;
    do
    {
        while (box[left].x < pivot)
            left++;
        while (box[right].x > pivot)
            right--;
        if (left <= right)
        {
            temp = box[left].x;
            box[left].x = box[right].x;
            box[right].x = temp;
            temp = box[left].y;
            box[left].y = box[right].y;
            box[right].y = temp;
            left++;
            right--;
        }
    } while (left <= right);
    if (L < right)
    {
        x_qsort(box, L, right);
    }
    if (left < R)
    {
        x_qsort(box, left, R);
    }
}

void y_qsort(t_list *box, int L, int R)
{
    int left = L, right = R, temp, pivot = box[(L + R) / 2].y;
    do
    {
        while (box[left].y < pivot)
            left++;
        while (box[right].y > pivot)
            right--;
        if (left <= right)
        {
            temp = box[left].x;
            box[left].x = box[right].x;
            box[right].x = temp;
            temp = box[left].y;
            box[left].y = box[right].y;
            box[right].y = temp;
            left++;
            right--;
        }
    } while (left <= right);
    if (L < right)
    {
        y_qsort(box, L, right);
    }
    if (left < R)
    {
        y_qsort(box, left, R);
    }
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    t_list box[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &box[i].x, &box[i].y);
    }
    y_qsort(box, 0, n - 1);
    x_qsort(box, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", box[i].x, box[i].y);
    }
}

// qsort(box, n, sizeof(t_list), compare);

// int compare(const void *a, const void *b)
// {
//     if (*(int *)a > *(int *)b)
//         return (1);
//     else if (*(int *)a < *(int *)b)
//         return (-1);
//

//   return (0);
// }

/*
1. [(3,4), (1,1), ]
sort()
*/