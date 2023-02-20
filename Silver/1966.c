#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int impo, idx;
	struct s_list *next;
} t_list;

void node_init(t_list *node)
{
	if (node->next == NULL)
		return ;
	t_list *temp = node->next;
	t_list *temp2;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	node->next = NULL;
}

t_list *ft_lstnew(int impo, int idx)
{
	t_list *new = (t_list *)malloc(sizeof(t_list));

	new->impo = impo;
	new->idx = idx;
	new->next = NULL;

	return (new);
}

void ft_lstadd_back(t_list **node, t_list *new)
{
	t_list *set = *node;

	if (set->next == NULL)
	{
		set->next = new;
		return;
	}
	while (set->next != NULL)
		set = set->next;
	set->next = new;
}

int check_impo(t_list *set, int impo)
{
	while (set->next != NULL)
	{
		set = set->next;
		if (set->impo > impo)
			return 1;
	}
	return 0;
}

void ret_print(t_list *node, int select)
{
	t_list *set, *pick;
	int idx = -1, order = 0;

	while (1)
	{
		set = node;
		pick = set->next;
		set->next = pick->next; // node seperate
		pick->next = NULL;
		if (check_impo(set, pick->impo)) // big -> go back
		{
			while (set->next != NULL)
				set = set->next;
			set->next = pick;
		}
		else // biggest one del, and count;
		{
			order++;
			idx = pick->idx;
			free(pick);
		}
		if (idx == select)
		{
			printf("%d\n", order);
			return;
		}
	}
}

int main()
{
	t_list *node = ft_lstnew(0, 0);
	int all, n, impo, idx;
	scanf("%d", &all);
	for (int i = 0; i < all; i++)
	{
		node_init(node);
		scanf("%d %d", &n, &idx);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &impo);
			ft_lstadd_back(&node, ft_lstnew(impo, j));
		}
		ret_print(node, idx);
	}
}