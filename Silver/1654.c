#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    long long a = *(long long *)x;
    long long b = *(long long *)y;

    return (a - b);
}

void input_box(long long *box, long long k)
{
    for (long long i = 0; i < k; i++)
    {
        scanf("%lld", &box[i]);
    }
    qsort(box, k, sizeof(long long), compare);
}

#define SUCCESS 0
#define HIGH 1
#define LOW -1

long long key_set(long long *box, long long mid, long long *key, long long k, long long n)
{
    long long l;

    l = 0;
    for (long long i = 0; i < k; i++)
    {
        l += box[i] / mid;
    }
    if (l < n)
        return (HIGH);
    // if (l == n)
    // {
    //     *key = mid;
    //     return (SUCCESS);
    // }
    if (l >= n)
    {
        if (*key < mid)
            *key = mid;
        return (LOW);
    }
    return (-2);
}

long long bin_search(long long *box, long long k, long long n)
{
    long long key = 0, ret, max = box[k - 1];
    long long left = 1, mid, right = max;
    while (left <= right)
    {
        mid = (left + right) / 2;
        ret = key_set(box, mid, &key, k, n);
        // if (ret == SUCCESS)
        //     return (key);
        if (ret == HIGH)
            right = mid - 1;
        else if (ret == LOW)
            left = mid + 1;
    }
    return (key); // 최댓값
}

int main()
{
    long long k, n;
    long long ret;
    scanf("%lld %lld", &k, &n);
    long long box[k];
    input_box(box, k);
    ret = bin_search(box, k, n);
    printf("%lld\n", ret);
}