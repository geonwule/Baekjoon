#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int content;
    struct s_list *next;
    struct s_list *prev;
} t_list;

t_list *ft_lstnew(int content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (0);
    new->content = content;
    new->next = NULL;
    new->prev = NULL;
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
    new->prev = ft_lstlast(temp);
    ft_lstlast(temp)->next = new;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list *temp = *lst;

    if (new == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    new->next = temp;
    temp->prev = new;
    *lst = new;
}

void order_empty(int size)
{
    if (size == 0)
        printf("1\n");
    else
        printf("0\n");
}

void order_push(t_list **deck, char *order)
{
    int temp;

    scanf("%d", &temp);
    if (order[5] == 'f') // push_front
    {
        ft_lstadd_front(deck, ft_lstnew(temp));
    }
    else // push_back
    {
        ft_lstadd_back(deck, ft_lstnew(temp));
    }
}

void lstdel_front(t_list **lst)
{
    t_list *temp;
    t_list *temp2 = *lst;

    printf("%d\n", temp2->content);
    temp = temp2->next;
    free(temp2);
    if (temp == NULL)
    {
        *lst = NULL;
        return ;
    }
    temp->prev = NULL;
    *lst = temp;
}

void lstdel_back(t_list **lst)
{
    t_list *temp;
    t_list *temp2 = *lst;
    t_list *last = ft_lstlast(temp2);
    printf("%d\n", last->content);
    temp = last->prev;
    free(last);
    if (temp == NULL)
    {
        *lst = NULL;
        return ;
    }
    temp->next = NULL;
}

void order_pop(t_list **deck, char *order, int *size)
{
    if (*size == 0)
    {
        printf("-1\n");
        return;
    }
    *size -= 1;
    if (order[4] == 'f') // pop_front
    {
        lstdel_front(deck);
    }
    else // pop_back
    {
        lstdel_back(deck);
    }
}

void order_front(t_list *deck, int size)
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", deck->content);
}

void order_back(t_list *deck, int size)
{
    t_list *temp = ft_lstlast(deck);

    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", temp->content);
}

int main()
{
    t_list *deck = NULL;
    t_list *front = deck;
    t_list *back;
    int n, size = 0;
    char order[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", order);
        if (order[1] == 'u')
        {
            order_push(&deck, order);
            size++;
        }
        else if (order[1] == 'o')
            order_pop(&deck, order, &size); // size-- or size maintain
        else if (order[0] == 's')
            printf("%d\n", size);
        else if (order[0] == 'e')
            order_empty(size);
        else if (order[0] == 'f')
            order_front(deck, size);
        else if (order[0] == 'b')
            order_back(deck, size);
        else
        {
            printf("Error\n");
            return (0);
        }
        // front = deck;
        // back = ft_lstlast(deck);
        // printf("front : %d, back : %d\n", front->content, back->content);
    }
}