#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    int a = *(int *)x;
    int b= *(int *)y;
    return (a - b);
}

void    arr_init(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int sum_set(int *arr, int n)
{
    int sum = 0, ret = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        ret += sum;
    }
    return (ret);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    arr_init(arr, n);
    qsort(arr, n, sizeof(int), compare);
    int sum = sum_set(arr, n);
    printf("%d\n", sum);
}