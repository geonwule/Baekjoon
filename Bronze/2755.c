#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A+: 4.3, A0: 4.0, A-: 3.7

// B+: 3.3, B0: 3.0, B-: 2.7

// C+: 2.3, C0: 2.0, C-: 1.7

// D+: 1.3, D0: 1.0, D-: 0.7

// F: 0.0

typedef struct s_list
{
    int     index;
    int     hakjum;
    double         value;
    struct s_list *next;
}   t_list ;


double plus_minus(char c)
{
    if (c == '+')
        return (0.3);
    else if (c == '-')
        return (-0.3);
    return (0);
}

double sung_jeok(char *s)
{
    double ret = 0.00;
    int i = 0;

        if (s[i] == 'A')
            ret += 4;
        else if(s[i] == 'B')
            ret += 3;
        else if(s[i] == 'C')
            ret += 2;
        else if(s[i] == 'D')
            ret += 1;
        else if(s[i] == 'F')
            return (ret);
        i++;
        ret += plus_minus(s[i]);
        return (ret);
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

double  pyung_gyun(t_list *ret)
{
    t_list  *prev = ret;
    double  value = 0;
    double  hakjum = 0;
    double  result;

    while (ret)
    {
        hakjum += ret->hakjum;
        value += ret->value * ret->hakjum;
        ret = ret->next;
    }

    result = value / hakjum;
    return (result);
}

int main()
{
    int n;
    t_list  *ret = NULL;
    char name[101];
    int  hak;
    char *value;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        value = (char *)malloc(sizeof(char) * 3);
        scanf("%s", name);
        scanf("%d", &hak);
        scanf("%s", value);
        ft_lstadd_back(&ret, ft_lstnew(i+1, hak, value));
    }
    printf("%.2f\n", pyung_gyun(ret) + 0.001);
}