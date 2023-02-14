#include <stdio.h>

typedef struct s_list
{
    int age;
    char *name;
} t_list;

#include <stdlib.h>

int main()
{
    int n, age, t_age, j;
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
            t_age = age;
            t_name = name;
            while (box[j].age > age && j < n)
            {
                t_age = box[j].age;
                t_name = box[j].name;
                box[j].age = t_age;
                box[j].name = t_name;
                j++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", box[i].age, box[i].name);
    }
}