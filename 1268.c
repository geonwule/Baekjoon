#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	int value;
	int index;
	int *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(int *content, int idx)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->content = content;
	new->index = idx;
	new->value = 0;
	new->next = NULL;
	return (new);
}

t_list *ft_lstlast(t_list *lst)
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

int ft_lstsize(t_list *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int value_insert(t_list *point, t_list *ret, int idx)
{
	t_list *temp = ret;
	t_list *prev = ret;
	int value = 0;
	int i = 0;

	while (i < 5)
	{
		while (temp)
		{
			if (temp->index == idx)
				continue;
			if (point->content[i] == temp->content[i])
				value++;
			temp = temp->next;
		}
		temp = prev;
		i++;
	}
	return (value);
}

void set_value(t_list *ret, int size)
{
	t_list *temp = ret;

	while (temp)
	{
		temp->value = value_insert(temp, ret, temp->index);
		temp = temp->next;
	}
}

void	high_value(t_list *ret)
{
	int	who = 1;

	while (ret)
	{
		if (ret->next != NULL && (ret->value < ret->next->value))
			who = ret->next->index;
		ret = ret->next;
	}
	printf("%d\n", who);
}

int main()
{
	int a, n;
	t_list *ret;
	int *new;

	scanf("%d", &n);

	ret = NULL;
	for (int i = 1; i <= n; i++)
	{
		new = (int *)malloc(sizeof(int) * n);
		if (new == NULL)
			return (0);
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &a);
			new[j] = a;
		}
		ft_lstadd_back(&ret, ft_lstnew(new, i));
	}

	printf("ret lstsize = %d\n", ft_lstsize(ret));

	// while (ret)
	// {
	// 	int i = 0;
	// 	while (i < 5)
	// 	{
	// 		printf("%d ", ret->content[i]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	ret = ret->next;
	// }
	printf("ok");
	set_value(ret, n);
	printf("no ok");
	high_value(ret);	
}
