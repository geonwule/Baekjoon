#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
	struct s_list *prev;
} t_list;

t_list *ft_lstnew(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->content = content;
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}