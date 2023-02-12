#include <stdio.h>
#include <stdlib.h>

void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
// 1, 3, 4 ---< 2
void sort_oreum(int *box, int idx, int c)
{
    int temp, temp2;

    if (idx == 0)
    {
        box[0] = c;
        return;
    }
    for (int i = 0; i < idx; i++)
    {
        if (c < box[i])
        {
            temp = box[i];
            box[i] = c;
            for (int j = i + 1; j <= idx; j++)
            {
                temp2 = box[j];
                box[j] = temp;
                temp = temp2;
            }
            return;
        }
    }
    box[idx] = c; // c = max;
}

typedef struct s_list
{
    int box[1000000];
    struct s_list *next;
} t_list;

void main2(int *box, int n)
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        sort_oreum(box, i, temp);
    }
}

t_list  *ft_lstnew(void)
{
    t_list *new;
    new = (t_list*)calloc(1, sizeof(t_list));
    new->next = NULL;
    return (new);
}

int main()
{
    int n, new_n, temp;
    scanf("%d", &n);
    t_list *new = ft_lstnew();
    new_n = n;

    while (1)
    {
        if (new_n > 1000000)
        {
            new_n -= 1000000;
            main2(new->box, 1000000);
        }
        else
        {
            main2(new->box, new_n);
            break;
        }
    }
    while (new)
    {
        if (new->next == NULL)
        {
            for (int i = 0; i < n % 1000000; i++)
                printf("%d\n", new->box[i]);
        }
        else
        {
            for (int i = 0; new->box[i] != 0; i++)
                printf("%d\n", new->box[i]);
        }
        new = new->next;
    }
}