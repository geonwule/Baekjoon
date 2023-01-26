#include <stdio.h>
#include <stdlib.h>


typedef struct s_list
{
    int     sc;
    char    *name;
    int     num;
    struct s_list *next;
}   t_list ;

int main()
{
    int stu_n;
    int sc = 1;

    while (1)
    {
        scanf("%d", &stu_n);
        if (stu_n == 0)
            break ;
        for (int i = 0; i < stu_n; i++)
        {
            
        }
    }

}

//util_list
t_list *ft_lstnew(int index, int hak, char *value)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->index = index;
	new->hakjum = hak;
	new->value = sung_jeok(value);
	new->next = NULL;
	return (new);
}

//util_list
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

//util_list
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

//util_list
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
