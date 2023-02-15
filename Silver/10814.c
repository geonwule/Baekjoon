#include <stdio.h>

typedef struct s_list
{
    int age;
    char *name;
} t_list;

#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (a > b)
        return (1);
    else if (a < b)
        return (-1);
    else
        return (0);
    return (0);
}

int main()
{
    int n, age, t_age, j, flag;
    char *name, *t_name;
    scanf("%d", &n);
    t_list box[n];
    for (int i = 0; i < n; i++)
    {
        name = malloc(101);
        scanf("%d %s", &age, name);
        box[i].age = age;
        box[i].name = name;
    }
    qsort(box, n, sizeof(t_list), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", box[i].age, box[i].name);
    }
}

/*  time over..
int main()
{
    int n, age, t_age, j, flag;
    char *name, *t_name;
    scanf("%d", &n);
    t_list box[n];
    for (int i = 0; i < n; i++)
    {
        name = malloc(101);
        scanf("%d %s", &age, name);
        if (i == 0)
        {
            box[i].age = age;
            box[i].name = name;
        }
        else
        {
            j = 0;
            flag = 0;
            while (j < i)
            {
                if (flag == 0 && box[j].age > age)
                {
                    t_age = box[j].age;
                    t_name = box[j].name;
                    box[j].age = age;
                    box[j].name = name;
                    age = t_age;
                    name = t_name;
                    flag++;
                }
                else if (flag != 0)
                {
                    t_age = box[j].age;
                    t_name = box[j].name;
                    box[j].age = age;
                    box[j].name = name;
                    age = t_age;
                    name = t_name;
                    flag++;
                }
                j++;
            }
            box[i].age = age;
            box[i].name = name;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", box[i].age, box[i].name);
    }
}*/