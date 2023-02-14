#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int x;
    int y;
    struct s_list *next;
    struct s_list *prev;
} t_list;

t_list *ft_lstnew(int x, int y)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (0);
    new->x = x;
    new->y = y;
    new->next = NULL;
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
    t_list *head;
    int t_x, t_y;

    if (new == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    temp = *lst;
    head = temp;
    while (temp)
    {
        if (temp->x < new->x)
            break ;
        else if (temp->x > new->x || (temp->x == new->x && temp->y > new->y))
        {
            t_x = temp->x;
            t_y = temp->y;
            temp->x = new->x;
            temp->y = new->y;
            new->x = t_x;
            new->y = t_y;
        }
        temp = temp->next;
    }
    ft_lstlast(head)->next = new;
}

int main()
{
    int n, a, b;
    t_list *box = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        ft_lstadd_back(&box, ft_lstnew(a, b));
    }
    while (box)
    {
        printf("%d %d\n", box->x, box->y);
        box = box->next;
    }
}