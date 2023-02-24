#include <stdio.h>
#include <stdlib.h>

int arr_set(int *arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    return (sum);
}

void sansul_average(int sum, int n)
{
    double a = sum, b = n, minus = 1;
    double san_av = (double)(a / b) * 10;
    if (san_av < 0)
    {
        san_av *= -1;
        minus = -1;
    }
    if ((int)san_av % 10 >= 5)
    {
        san_av /= 10;
        san_av += 1;
    }
    else
        san_av /= 10;
    san_av *= minus;
    printf("%d\n", (int)san_av);
}

int compare(const void *x, const void *y)
{
    int a = *(int *)x;
    int b = *(int *)y;

    return (a - b);
}

void mid_print(int *arr, int n)
{
    printf("%d\n", arr[n / 2]);
}

void many_2nd_min(int *arr, int n)
{
    int min[4], second = 0;
    min[0] = 1;      // how many
    min[1] = arr[0]; // what
    min[2] = 0;      // new_one how many
    min[3] = 0;      // new_one what

    for (int i = 1; i < n; i++)
    {
        if (min[1] == arr[i])
            min[0] += 1;
        else if (min[2] == 0) // new one first
        {
            min[2] = 1;
            min[3] = arr[i];
        }
        else if (min[3] != arr[i]) // new one
        {
            if (min[2] == min[0] && second == 0)
            {
                min[1] = min[3];
                second = 1;
            }
            else if (min[2] > min[0])
            {
                min[0] = min[2];
                min[1] = min[3];
                second = 0;
            }
            min[2] = 1;
            min[3] = arr[i];
        }
        else if (min[3] == arr[i])
            min[2] += 1;
        else if (min[3] == arr[i])
        {
            min[2] += 1;
        }
    }
    if (min[2] == min[0] && second == 0)
    {
        min[1] = min[3];
        second = 1;
    }
    else if (min[2] > min[0])
    {
        min[0] = min[2];
        min[1] = min[3];
        second = 0;
    }
    printf("%d\n", min[1]);
}

void    max_minus_min(int *arr, int n)
{
    printf("%d\n", arr[n - 1] - arr[0]);
}

int main()
{
    int n, sum;
    scanf("%d", &n);
    int arr[n];
    sum = arr_set(arr, n);
    sansul_average(sum, n);
    qsort(arr, n, sizeof(int), compare);
    mid_print(arr, n);
    many_2nd_min(arr, n);
    max_minus_min(arr, n);
}