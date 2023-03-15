#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char *a, char *b)
{
    char st1[50];
    char st2[50];

    strncpy(st1, a, strlen(a));
    strncpy(st1 + strlen(a), b, strlen(b));
    strncpy(st2, b, strlen(b));
    strncpy(st2 + strlen(b), a, strlen(a));
    int len = strlen(st1);
    for (int i = 0; i < len; i++)
    {
        if (st1[i] > st2[i])
            return (1);
        else if (st1[i] < st2[i])
            return (-1);
        else
            continue ;
    }
    return (0);
}

void ft_qsort(int *arr, int L, int R)
{
    int left = L, right = R;
    int pivot = arr[(L + R) / 2];
    int temp;
    while (left <= right)
    {
        while (arr[left] > pivot)
            left++;
        while (arr[right] < pivot)
            right--;
        if (left <= right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    if (L < right)
        ft_qsort(arr, L, right);
    if (R > left)
        ft_qsort(arr, left, R);
}

int main()
{
    int arr[10] = {10, 5, 44, 1, 9};

    ft_qsort(arr, 0, 4);
    for (int i = 0 ; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}