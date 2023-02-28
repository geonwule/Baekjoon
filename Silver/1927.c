#include <stdio.h>
#include <stdlib.h>

typedef struct s_que
{
    long long hip;
    struct s_que *next;
} t_que;

t_que *que_new(long long i)
{
    t_que *new = (t_que *)malloc(sizeof(t_que));
    new->hip = i;
    new->next = NULL;
    return (new);
}

void ft_add_front(t_que **que, t_que *new)
{
    if (que == NULL)
    {
        *que = new;
        return;
    }
    new->next = *que;
    *que = new;
}

void ft_pop(t_que **que)
{
    t_que *temp = (*que);
    // if ((*que)->next == NULL)
    //     (*que) = NULL;
    // else
    (*que) = (*que)->next;
    free(temp);
}

void push_in(t_que *que, t_que *new)
{
    t_que *temp = que;

    if (que->next == NULL)
    {
        que->next = new;
        return;
    }
    que = que->next;
    while (que)
    {
        if (new->hip <= que->hip)
        {
            temp->next = new;
            new->next = que;
            return;
        }
        if (que->next == NULL)
        {
            que->next = new;
            return;
        }
        temp = que;
        que = que->next;
    }
}

void que_free(t_que *que)
{
    t_que *temp;

    while (que)
    {
        temp = que;
        que = que->next;
        free(temp);
    }
}

int main()
{
    int n;
    t_que *que = NULL;
    long long temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &temp);
        if (temp == 0)
        {
            if (que == NULL)
                printf("0\n");
            else
            {
                printf("%lld\n", que->hip);
                ft_pop(&que);
            }
        }
        else
        {
            if (que == NULL || que->hip >= temp)
            {
                ft_add_front(&que, que_new(temp));
            }
            else
            {
                push_in(que, que_new(temp));
            }
        }
    }
    que_free(que);
}