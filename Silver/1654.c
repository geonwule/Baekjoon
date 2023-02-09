#include <stdio.h>

void k_equl_n(int k, int n)
{
    int ret = 1073741830, temp;

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &temp);
        if (ret > temp)
            ret = temp;
    }
    printf("%d\n", ret);
}

void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void input_box(int *box, int k)
{
    int temp;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &box[i]);
    }
    for (int i = 0; i < k; i++)
    {
        temp = i;
        for (int j = i; j < k; j++)
        {
            if (box[temp] > box[j])
                temp = j;
        }
        ft_swap(&box[i], &box[temp]);
    }
}

#define SUCCESS 0
#define HIGH 1
#define LOW -1

int key_set(int *box, int mid, int *key, int k, int n)
{
    int l;

    l = 0;
    for (int i = 0; i < k; i++)
    {
        l += box[i] / mid;
    }
    if (l < n)
        return (HIGH);
    if (l >= n)
    {
        if (key_set(box, mid+1, key, k, n) == HIGH)
        {
            *key = mid;
            return (SUCCESS);
        }
        else
            return (LOW);   
    }
    return (-2);
}

int bin_search(int *box, int k, int n)
{
    int key, ret, max = box[k - 1];
    long long left = 0, mid, right = max;
    while (left <= max)
    {
        mid = (left + right) / 2;
        ret = key_set(box, mid, &key, k, n);
        if (ret == SUCCESS)
            return (key);
        else if (ret == HIGH)
            right = mid - 1;
        else if (ret == LOW)
            left = mid + 1;
    }
    return (-1); // error
}

int main()
{
    int k, n, ret;
    scanf("%d %d", &k, &n);
    int box[k];

    if (k == n)
    {
        k_equl_n(k, n);
        return (0);
    }
    input_box(box, k);
    ret = bin_search(box, k, n);
    printf("%d\n", ret);
}

// printf("min = %d\n", min);
// for (int i = 0; i < k; i++)
//     printf("%d\n", box[i]);
// printf("\n");