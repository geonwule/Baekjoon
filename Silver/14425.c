#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10001

typedef struct s_node
{
	char str[501];
	int cnt;
	struct s_node *next;
} t_node;

t_node *str[MAX_SIZE];

void str_init(void)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		str[i] = NULL;
	}
}

int hash(char *s)
{
	int hash = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		hash = hash + (s[i] * (i + 1));
	}
	return (hash % 10000);
}

void input_n(int n)
{
	t_node *temp;
	int idx;

	for (int i = 0; i < n; i++)
	{
		temp = (t_node *)malloc(sizeof(t_node));
		scanf("%s", temp->str);
		temp->cnt = 1;
		idx = hash(temp->str);
		if (str[idx] == NULL)
			str[idx] = temp;
		else
		{
			temp->next = str[idx];
			str[idx] = temp;
			str[idx]->cnt = 2;
		}
	}
}

int	find_node(char *s, int idx)
{
	t_node *temp = str[idx];

	while (temp)
	{
		if (strcmp(s, temp->str) == 0)
			return (1);
		temp = temp->next;
	}
	return(0);
}

int main()
{
	str_init();
	int n, m, idx, ret = 0;
	scanf("%d %d", &n, &m);
	input_n(n);
	char temp[501];
	for (int i = 0; i < m; i++)
	{
		scanf("%s", temp);
		idx = hash(temp);
		if (str[idx] && str[idx]->cnt == 1)
			ret++;
		else if (find_node(temp, idx))
			ret++;
	}
	printf("%d\n", ret);
}