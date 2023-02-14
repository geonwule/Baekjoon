#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int content;
    int idx;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(int content, int idx)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (0);
    new->next = NULL;
    new->content = content;
    new->idx = idx;
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
        return;
    }
    temp = *lst;
    ft_lstlast(temp)->next = new;
}

void sort_oreum(t_list *head, int c, int idx)
{
    t_list *temp = head;
    int tempo, tempo2;

    if (head->next == NULL)
    {
        head->content = c;
        return ;
    }
    while (temp)
    {
        if (temp->content > c)
        {
            tempo = temp->content;
            temp->content = c;
            temp = temp->next;
            while (temp)
            {
                tempo2 = temp->content;
                temp->content = tempo;
                tempo = tempo2;
                temp = temp->next;
            }
            return ;
        }
        temp = temp->next;
    }
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    t_list *head = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        ft_lstadd_back(&head, ft_lstnew(temp, i));
        sort_oreum(head, temp, i);
    }
    while (head)
    {
        printf("%d\n", head->content);
        head = head->next;
    }
}
