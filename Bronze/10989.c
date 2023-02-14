#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int box[100000];
    int idx;
    struct s_list *next;
    struct s_list *prev;
} t_list;

t_list *ft_lstnew(int index)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (0);
    new->next = NULL;
    new->idx = index;
    return (new);
}

static t_list *ft_lstlast(t_list *lst)
{
    t_list *last;

    if (lst == NULL)
        return (0);
    while (lst)
    {
        last = lst;
        lst = lst->next;
    }
    return (last);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    if (new == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        new->prev = NULL;
        return;
    }
    temp = *lst;
    new->prev = ft_lstlast(temp);
    ft_lstlast(temp)->next = new;
}

void sort_oreum(t_list *head, int *box, int idx, int c)
{
    t_list *t_head = head, *t_head2;
    int temp, temp2, flag;

    if (head->next == NULL)
    {
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
    else
    {
        while (t_head)
        {
            if (t_head == ft_lstlast(head))
            {
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
            else
            {
                for (int i = 0; i < 100000; i++)
                {
                    if (c < t_head->box[i])
                    {
                        temp = t_head->box[i];
                        t_head->box[i] = c;
                        t_head2 = t_head;
                        flag = 0;
                        while (t_head2)
                        {
                            if (flag == 0)
                            {
                                for (int j = i + 1; j < 100000; j++)
                                {
                                    temp2 = t_head->box[j];
                                    t_head->box[j] = temp;
                                    temp = temp2;
                                    flag = 1;
                                    if (temp == 0)
                                        return;
                                }
                            }
                            else
                            {
                                for (int j = 0; j < 100000; j++)
                                {
                                    temp2 = t_head->box[j];
                                    t_head->box[j] = temp;
                                    temp = temp2;
                                    flag = 1;
                                    if (temp == 0)
                                        return;
                                }
                            }
                            t_head2 = t_head2->next;
                        }
                    }
                    return;
                }
            }
            t_head = t_head->next;
        }
        t_head->box[idx] = c; // c = max;
    }
}

void main2(t_list *head, int *box, int n)
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        sort_oreum(head, box, i, temp);
    }
}

int main()
{
    int n, new_n, i = 1;
    scanf("%d", &n);
    t_list *head = NULL;
    t_list *temp;
    new_n = n;

    while (1)
    {
        temp = ft_lstnew(i++);
        ft_lstadd_back(&head, temp);
        if (new_n > 1000000)
        {
            new_n -= 1000000;
            main2(head, temp->box, 1000000);
        }
        else
        {
            main2(head, temp->box, new_n);
            break;
        }
    }
    while (head)
    {
        for (int i = 0; head->box[i] != 0 && i < 100000; i++)
            printf("%d\n", head->box[i]);
        head = head->next;
    }
}