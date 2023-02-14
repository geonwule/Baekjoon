#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int idx;
    struct s_list *next;
    struct s_list *prev;
}   t_list;

t_list *ft_lstnew(int idx)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->idx = idx;
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

void    yes_or_no(t_list *box)
{
    while (box)
    {
        if (box->idx == 1)
            printf("yes\n");
        else
            printf("no\n");
        box = box->next;
    }
}

int int_len(int a)
{
    int ret = 0;
    while (a)
    {
        ret++;
        a /= 10;
    }
    return (ret);
}

int pelind_check(int a)
{
    int a_len = int_len(a);
    int ten, or_len = a_len;
    for (int i = 0; i < or_len / 2; i++)
    {
        a_len = int_len(a);
        ten = 1;
        for (int i = 0; i < a_len - 1; i++)
            ten *= 10; 
        if (a % 10 != a / ten)
            return (0);
        a_len--;
        a -= ten * (a % 10);
        a /= 10;
    }
    return (1);
}

int main()
{
    t_list *box = NULL;
    int temp;

    while (1)
    {
        scanf("%d", &temp);
        if (temp == 0)
            break ;
        ft_lstadd_back(&box, ft_lstnew(pelind_check(temp)));
    }
    yes_or_no(box);
}