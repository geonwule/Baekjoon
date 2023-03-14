#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//n_max = 1000000

typedef	struct s_com
{
	char	name[10];
}	t_com;

int	compare(const void *x,  const void *y)
{
	return (strcmp((char *)y, (char *)x));
}

int	out_check(t_com *name, int n, int *idx)
{
	int i = *idx;
	int cnt = 1;
	char t[10];
	strcpy(t, name[i].name);
	while (++i < n)
	{
		if (strcmp(t, name[i].name) == 0)
			cnt++;
		else
			break ;
	}
	*idx = i - 1;
	if (cnt % 2 != 0)
		return (1);
	else
		return (0);
}

int main()
{
	int n;
	char temp[10];
	scanf ("%d", &n);
	t_com	*name = (t_com *)malloc(sizeof(t_com) * (n));
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", name[i].name, temp);
	}
	qsort(name, n, sizeof(name->name), compare);
	for (int i = 0; i < n; i++)
	{
		if (out_check(name, n, &i))
			printf("%s\n", name[i].name);
	}
}