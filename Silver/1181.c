#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
    int len;
    char name[51];
} t_list;

int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    return (0);
}

void dic_sort(t_list *box, int n)
{
    char temp[51];
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (box[i].len == box[k].len)
            {
                for (int j = 0; j < box[i].len; j++)
                {
                    if (box[i].name[j] > box[k].name[j])
                    {
                        strncpy(temp, box[i].name, box[i].len);
                        strncpy(box[i].name, box[k].name, box[i].len);
                        strncpy(box[k].name, temp, box[i].len);
                    }
                }
            }
            else
                break ;
        }
        printf("%s\n", box[i].name);
    }
}

int double_string(t_list *box, int idx, char *str, int str_len)
{
    int same;
    for (int i = 0; i < idx; i++)
    {
        if (box[i].len == str_len)
        {
            for (int j = 0; j < str_len; j++)
            {
                if (box[i].name[j] != str[j])
                {
                    same = 0;
                    break ;
                }
                same = 1;
            }
            if (same == 1)
                return 1;
        }
    }
    return (0);
}

int main()
{
    int n, new;
    scanf("%d", &n);
    t_list box[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", box[i].name);
        box[i].len = strlen(box[i].name);
        if (double_string(box, i, box[i].name, box[i].len))
            i--;
        new = i;
    }
    qsort(box, n, sizeof(t_list), compare);
    dic_sort(box, n);
    for (int i = 0; i <= new; i++)
    {
        printf("%s\n", box[i].name);
    }
}