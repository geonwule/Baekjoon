#include <stdio.h>

int max_heap[100001] = { 0, }; // index 1 ~ 100000
int idx = 1; // index 1 init

void    insert(int var)
{
    int var_idx = idx, temp;
    max_heap[idx++] = var;
    while (var_idx > 1)
    {
        if (max_heap[var_idx] > max_heap[var_idx / 2])
        {
            temp = max_heap[var_idx];
            max_heap[var_idx] = max_heap[var_idx / 2];
            max_heap[var_idx / 2] = temp;
            var_idx /= 2;
        }
        else
            break ;
    }
}

void    heap_react(int i)
{
    int left = i * 2;
    int right = i * 2 + 1;
    int big = i;
    int temp;

    if (left < idx && max_heap[left] > max_heap[big])
        big = left;
    if (right < idx && max_heap[right] > max_heap[big])
        big = right;
    if (big != i)
    {
        temp = max_heap[big];
        max_heap[big] = max_heap[i];
        max_heap[i] = temp;
        heap_react(big);
    }
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp == 0)
        {
            if (idx == 1)
                printf("0\n");
            else
            {
                printf("%d\n", max_heap[1]);
                max_heap[1] = max_heap[--idx]; // replace root in last idx
                heap_react(1);
            }
        }
        else
            insert(temp);
    }
}