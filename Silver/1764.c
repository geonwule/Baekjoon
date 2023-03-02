#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[500001][21];
char un_seen[500001][21];
int idx[500000];
int idx_i = 0;

/*
void init_go(void)
{
    str=(char**)malloc(sizeof(char*)*500001);
    for(int i=0;i<500000;i++)
    {
        str[i]=(char*)malloc(21);
    }
    idx=(int*)calloc(500000, sizeof(int));
}
*/

size_t hash[500000];

size_t hash_5454(char *str)
{
    size_t hash = 5454;

    for (int i = 0; str[i] != '\0'; i++)
        hash = hash * str[i];
    return (hash);
}

int compare(const void *x, const void *y)
{
    char *a = (char *)x;
    char *b = (char *)y;
    return (strcmp(a, b));
}

int main()
{
    // init_go();
    int n, m;
    char temp[21];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
        hash[i] = hash_5454(str[i]);
    }
    // qsort(str, n, sizeof(char*), compare);
    size_t t_hash;
    for (int i = 0; i < m; i++)
    {
        scanf("%s", temp);
        for (int j = 0; j < n; j++)
        {
            t_hash = hash_5454(temp);
            if (hash[j] == t_hash)
            {
                idx[idx_i++] = j;
                break;
            }
        }
    }
    printf("%d\n", idx_i);
    if (idx_i > 0)
    {
        for (int i = 0; i < idx_i; i++)
        {
            printf("%s\n", str[idx[i]]);
        }
    }
}