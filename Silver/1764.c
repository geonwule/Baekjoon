#include <stdio.h>
#include <stdlib.h>

typedef struct s_name
{
    char    name[21];
}   t_name;

long long	hash(char *s)
{
	long long	a = 0;
	for (int i = 0; s[i] != '\0'; i++)
		a += (i + 1) * (s[i]);
	return (a);
}

int no_listen[100000] = {0, };

void    no_listen_init(int n)
{
    char temp[21];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        no_listen[hash(temp)] = 1;
    }
}

#include <string.h>

int compare(const void *x, const void *y)
{
    char *a = (char *)x;
    char *b = (char *)y;

    return (strcmp(a, b));    
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    t_name *str = (t_name *)malloc(sizeof(t_name) * (1000001));
    t_name *ret = (t_name *)malloc(sizeof(t_name) * (500001));
    int ret_i = 0;
    for (int i = 0; i < n + m; i++)
    {
        scanf("%s", str[i].name);
    }
    qsort(str, n+m, sizeof(str[0]), compare);
    for (int i = 0; i + 1 < n + m; i++)
    {
        if (strcmp(str[i].name, str[i+1].name) == 0)
        {
            strcpy(ret[ret_i++].name, str[i].name);
            i++;
        }
    }
    printf("%d\n", ret_i);
    for (int i = 0; i < ret_i; i++)
        printf("%s\n", ret[i].name);
}

/*
int main()
{
    int n, m;
    char temp[21];
    t_name *ret = (t_name *)malloc(sizeof(t_name) * (500001));
    int ret_i = 0;
    scanf ("%d %d", &n, &m);
    no_listen_init(n);
    for(int i = 0 ; i < m; i++)
    {
        scanf("%s", temp);
        if (no_listen[hash(temp)])
        {
            strcpy(ret[ret_i++].name, temp);
        }
    }
    qsort(ret, ret_i, sizeof(ret[0]), compare);
    printf("%d\n", ret_i);
    for (int i = 0; i < ret_i; i++)
    {
        printf("%s\n", ret[i].name);
    }
    free(ret);
}*/