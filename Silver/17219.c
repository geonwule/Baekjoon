#include <stdio.h>

char psw[100001][21] = {0, };

int	sum(char *s)
{
	int sum = 0;
	for (int i = 0; s[i] != '\0'; i++)
		sum += (s[i] * (i + 1));
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
		idx = sum(juso);
		scanf("%s", psw[idx]);
	}
}

int main()
{
	int n, m, idx;
	char find[21];
	scanf("%d %d", &n, &m);
	site_psw_init(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", find);
		idx = sum(find);
		printf("%s\n", psw[idx]);
	}
}