#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    char *content;
    struct s_list *next;
    struct s_list *prev;
} t_list;

void max_set(int *max, int *n1, int *n2, int a, int b, int c)
{
    *max = a;
    if (*max < b)
    {
        *max = b;
        if (*max < c)
            *max = c;
    }
    if (*max == a)
    {
        *n1 = b;
        *n2 = c;
    }
    else if (*max == b)
    {
        *n1 = a;
        *n2 = c;
    }
    else if (*max == c)
    {
        *n1 = a;
        *n2 = b;
    }
}

void    add_back(t_list *new, int w_r)
{
    char *txt;
    t_list  *temp = new;

    txt = malloc(6);
    if (w_r == -1)
        txt = "wrong";
    else
        txt = "right";
    if (new == NULL)
    {
        new->content = txt;
        new->next = NULL;
        return ;
    }
    while (temp)
        temp = temp->next;
    temp->content = txt;
    temp->next = NULL;
}
void    print_list(t_list *new)
{
    while (new)
    {
        printf("%s\n", new->content);
        new = new->next;
    }
}

void    mal_free(t_list *new)
{
    while (new)
    {
        free(new->content);
        new = new->next;
    }
    free(new);
}

t_list  *list_new(char *content)
{
    t_list  *new;

    new = (t_list *)malloc(sizeof(t_list));
    new->content = content;
}

int main()
{
    t_list *new = list_new(NULL);
    int a, b, c, max, n1, n2;
    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
            break;
        if (a == b || a == c || b == c)
        {
            add_back(new, -1);  // wrong
            continue;
        }
        max_set(&max, &n1, &n2, a, b, c);
        if (max * max == n1 * n1 + n2 * n2)
            add_back(new, 1);   // right
        else
            add_back(new, -1);    // wrong
    }
    print_list(new);
    mal_free(new);
}