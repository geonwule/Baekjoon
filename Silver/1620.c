#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct s_dogam
{
	char monster[21];
}	t_dogam;

typedef struct s_node
{
	char monster[21];
	int number;
	struct s_node *next;
}	t_node;

typedef struct s_table
{
	t_node *node;
	int cnt;
}	t_table;
t_dogam	dogam[100002];
t_table	dogam2[100002];

void	dogam2_init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dogam2->node = NULL;
		dogam2->cnt = 0;
	}
}

int hash(char *s)
{
	int hash = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		hash += (s[i] * (i + 1));
	}
	return (hash % 100000);
}

void	input_dogam(int n)
{
	int idx;
	t_node *new;

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", dogam[i].monster);
		idx = hash(dogam[i].monster);
		new = (t_node *)malloc(sizeof(t_node));
		new->number = i;
		strcpy(new->monster, dogam[i].monster);
		new->next = NULL;
		if (dogam2[idx].node == NULL)
			dogam2[idx].node = new;
		else
		{
			new->next = dogam2[idx].node;
			dogam2[idx].node = new;
		}
		dogam2[idx].cnt++;
	}
}

void	find_dogam2(char *temp, int idx)
{
	t_node *node = dogam2[idx].node;
	while (node)
	{
		if (strcmp(node->monster, temp) == 0)
		{
			printf("%d\n", node->number);
			return ;
		}
		node = node->next;
	}
}

int main()
{
	int n, m;
	char temp[21];
	scanf("%d %d", &n, &m);
	dogam2_init(n);
	input_dogam(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", temp);
		if (temp[0] >= '0' && temp[0] <= '9')
		{
			printf("%s\n", dogam[atoi(temp)].monster);
		}
		else
		{
			if (dogam2[hash(temp)].cnt == 1)
			{
				printf("%d\n", dogam2[hash(temp)].node->number);
			}
			else
				find_dogam2(temp, hash(temp));
		}
	}
}