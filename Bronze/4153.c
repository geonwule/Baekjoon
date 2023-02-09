#include <stdio.h>
#include <stdlib.h>


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

static t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	ft_lstlast(temp)->next = new;
}

void max_set(int *max, int *n1, int *n2, int a, int b, int c)
{
    *max = a;
    if (*max < b)
    {
        *max = b;
        if (*max < c)
            *max = c;
    }
    if (*max == a)
    {
        *n1 = b;
        *n2 = c;
    }
    else if (*max == b)
    {
        *n1 = a;
        *n2 = c;
    }
    else if (*max == c)
    {
        *n1 = a;
        *n2 = b;
    }
}

void    print_list(t_list *new)
{
    while (new)
    {
        printf("%s\n", new->content);
        new = new->next;
    }
}

void    mal_free(t_list *new)
{
    while (new)
    {
        free(new->content);
        new = new->next;
    }
    free(new);
}

int main()
{
    t_list *new = NULL;
    int a, b, c, max, n1, n2;
    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
            break;
        if (a == b || a == c || b == c)
        {
            ft_lstadd_back(&new, ft_lstnew("wrong"));  // wrong
            continue;
        }
        max_set(&max, &n1, &n2, a, b, c);
        if (max * max == n1 * n1 + n2 * n2)
            ft_lstadd_back(&new, ft_lstnew("right"));   // right
        else
            ft_lstadd_back(&new, ft_lstnew("wrong"));    // wrong
    }
    print_list(new);
    //mal_free(new);
}