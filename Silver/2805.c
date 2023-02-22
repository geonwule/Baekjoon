#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    return (y - x);
}

int ret_find_out(int *tree, int ret, int n, int m, int *max)
{
    long long sum = 0;

    for (int i = 0; tree[i] - ret > 0 && i < n; i++)
    {
        sum += tree[i] - ret;
    }
    if (sum == (long long)m)
    {
        *max = ret;
       return (0);
    }
    else if (sum < (long long)m)
        return (-1);
    else if (sum > (long long)m)
    {
        if (*max < ret)
            *max = ret;
        return (1);
    }
    return (0);
}

void binary_search(int *tree, int left, int right, int n, int m, int *max)
{
    int L = left, R = right, M = (L + R) / 2;
    int flag = ret_find_out(tree, M, n, m, max);
    if (flag == 0 || left > right)
    {
        printf("%d\n", *max);
        free(tree);
        return;
    }
    if (flag == -1)
    {
        binary_search(tree, left, M - 1, n, m, max);
    }
    else if (flag == 1)
    {
        binary_search(tree, M + 1, right, n, m, max);
    }
}

int main()
{
    int n, m, big = 0, cut = 1, ret;
    int *tree;
    scanf("%d %d", &n, &m);
    tree = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
    }
    qsort(tree, n, sizeof(int), compare);
    big = tree[0];
    cut = m / n;
    if (m % n != 0)
        cut += 1;
    int max = 0;
    binary_search(tree, big - m, big - cut, n, m, &max);
    // while (1)
    // {
    //     ret = big - cut;
    //     int num;
    //     for (int i = n - 1; tree[i] - ret <= 0; i--)
    //         num = i;
    //     if (cut * num < m)
    //     {
    //         cut++;
    //         continue;
    //     }
    // }
}
