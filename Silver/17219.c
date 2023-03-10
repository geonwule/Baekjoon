#include <stdio.h>

char psw[100001][21] = {0, };

int	sum(char *s)
{
	int sum = 0;
	for (int i = 0; s[i] != '\0'; i++)
		sum += s[i];
	return (sum);
}

int hashtable(char *s)
{
	int hash = sum(s);
	if (hash == 100000)
		return (hash);
	return (hash % 100000);
}

void site_psw_init(int n)
{
	int idx;
	char juso[21];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", juso);
		idx = hashtable(juso);
		scanf("%s", psw[idx]);
	}
}

int main()
{
	int n, m, idx;
	char find[21];
	int ret[100000];
	int ret_i = 0;
	scanf("%d %d", &n, &m);
	site_psw_init(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", find);
		idx = hashtable(find);
		ret[i] = idx;
	}
	for (int i = 0; i < m; i++)
		printf("%s\n", psw[ret[i]]);
}

// int idx_find(char *f, int n)
// {
// 	int i;

// 	for (i = 0; i < n; i++)
// 	{
// 		if (!strcmp(site[i], f))
// 			return (i);
// 	}
// 	return (-1);
// }