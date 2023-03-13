#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct s_node
{
	char *juso;
	char *pass;
	struct s_node *next;
}	t_node;

typedef struct s_table
{
	t_node *node;
	int	cnt;
}	t_table;

t_table *psw;
#define MAX_SIZE 100001

void	psw_init(void)
{
	psw = (t_table *)malloc(sizeof(t_table) * MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		psw->node = NULL;
		psw->cnt = 0;
	}
}

int	hash_table(char *s)
{
	int hash = 0;
	for (int i = 0; s[i] != '\0'; i++)
		hash += (s[i] * (i + 1));
	return (hash % 100000);
}

t_node	*new_node(char *juso, char *pass)
{
	t_node *new = (t_node *)malloc(sizeof(t_node));
	new->juso = juso;
	new->pass = pass;
	new->next = NULL;
	return (new);
}

void site_psw_init(int n)
{
	int idx;
	char *juso, *password;
	t_node *new;
	for (int i = 0; i < n; i++)
	{
		juso = malloc(21);
		password = malloc(21);
		scanf("%s %s", juso, password);
		new = new_node(juso, password);
		idx = hash_table(juso);
		if (psw[idx].node == NULL) //node가 비어있을 경우
		{
			psw[idx].node = new;
			psw[idx].cnt++;
		}
		else
		{
			new->next = psw[idx].node;
			psw[idx].node = new;
			psw[idx].cnt++;
		}
	}
}

void	find_pass(char *find, int idx)
{
	t_node *node = psw[idx].node;
	while (node)
	{
		if (strcmp(find, node->juso) == 0)
		{
			printf("%s\n", node->pass);
			return ;
		}
		node = node->next;
	}
}

int main()
{
	psw_init();
	int n, m, idx;
	char find[21];
	scanf("%d %d", &n, &m);
	site_psw_init(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", find);
		idx = hash_table(find);
		if (psw[idx].cnt == 1)
			printf("%s\n", psw[idx].node->pass);
		else
			find_pass(find, idx);
	}
}