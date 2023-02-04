#include <stdio.h>

// typedef struct s_club
// {
//     char *name;
//     int age;
//     int weight;
//     struct s_club   *next;
// }   t_club;

// t_club  *new_club(char *a, int b, int c)
// {
//     t_club  *new;

//     new = (t_club *)malloc(sizeof(t_club));
//     new->name = a;
//     new->age = b;
//     new->weight
//     return (new);
// }

void ret_set(char *ret, char *name, char j_or_s)
{
    char sen[8] = {'S', 'e', 'n', 'i', 'o', 'r', '\n', '\0'};
    char jun[8] = {'J','u','n','i','o','r','\n','\0'};
    int i = 0;
    while (ret[i] != 0)
        i++;
    int j = 0;
    while (name[j] != 0)
    {
        ret[i + j] = name[j];
        j++;
    }
    ret[i + j] = ' ';
    int k = i + j + 1;
    if (j_or_s == 'j')
    {
        for (int j = 0; j < 7; j++)
        {
            ret[k + j] = jun[j];
        }
    }
    if (j_or_s == 's')
    {
        for (int j = 0; j < 7; j++)
        {
            ret[k + j] = sen[j];
        }
    }
}

int main()
{
    char name[100000];
    int age, weight;
    char ret[100000] = {
        0,
    };
    char c;
    while (1)
    {
        scanf("%s %d %d", name, &age, &weight);
        if (name[0] == '#' && age == 0 && weight == 0)
            break;
        c = 'j';
        if (age > 17 || weight >= 80)
            c = 's';
        ret_set(ret, name, c);
    }
    printf("%s", ret);
}