#include <stdio.h>
<<<<<<< HEAD
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

int main()
{
	t_list *head;
	t_list *temp;

	head->prev = NULL;
	head = ft_lstnew("Hello");
	ft_lstadd_back(&head, ft_lstnew("hi"));
	ft_lstadd_back(&head, ft_lstnew("good"));
	ft_lstadd_back(&head, ft_lstnew("last"));
	temp = head;
	while (temp)
	{
		printf("corrent = %s\n", temp->content);
		if (temp->prev)
			printf("prev = %s\n", temp->prev->content);
		temp = temp->next;
	}
	temp = ft_lstlast(head);
	while (temp)
	{
		printf("%s\n", temp->content);
		temp = temp->prev;
	}
=======
#include <limits.h>

int main()
{
	int box[1000000];
	printf("%d\n",INT_MAX / 10000);

>>>>>>> 39f175a34f70686aa795a0798737f36a166df1ed
}