#include <stdio.h>
#include <string.h>

char site[100000][21], psw[100000][21];

void site_psw_init(int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", site[i], psw[i]);
	}
}

int idx_find(char *f, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (!strcmp(site[i], f))
			return (i);
	}
	return (-1);
}

int main()
{
	int n, m, idx;
	char find[21], ret[100000][21];
	int ret_i = 0;
	scanf("%d %d", &n, &m);
	site_psw_init(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", find);
		idx = idx_find(find, n);
		printf("%s\n", psw[idx]);
	}
}