#include <stdio.h>

int min_heap[100001] = { 0, }; // index 1 ~ 100000
int idx = 1; // index 1 init

void    insert(int var)
{
    int var_idx = idx, temp;
    min_heap[idx++] = var;
    while (var_idx > 1)
    {
        if (min_heap[var_idx] < min_heap[var_idx / 2])
        {
            temp = min_heap[var_idx];
            min_heap[var_idx] = min_heap[var_idx / 2];
            min_heap[var_idx / 2] = temp;
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
    int small = i;
    int temp;

    if (left < idx && min_heap[left] < min_heap[small])
        small = left;
    if (right < idx && min_heap[right] < min_heap[small])
        small = right;
    if (small != i)
    {
        temp = min_heap[small];
        min_heap[small] = min_heap[i];
        min_heap[i] = temp;
        heap_react(small);
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
                printf("%d\n", min_heap[1]);
                min_heap[1] = min_heap[--idx]; // replace root in last idx
                heap_react(1);
            }
        }
        else
            insert(temp);
    }
}