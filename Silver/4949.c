#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int no_symmetry(char *str)
{
    int s_L = 0, s_R = 0, b_L = 0, b_R = 0;
    for (int i = 0; str[i] != '.'; i++)
    {
        if (str[i] == '(')
            s_L++;
        else if (str[i] == ')')
            s_R++;
        else if (str[i] == '[')
            b_L++;
        else if (str[i] == ']')
            b_R++;
    }
    if (s_L - s_R != 0 || b_L - b_R != 0)
        return (1);
    return (0);
}

int balance_check(char *str)
{
    for (int i = 0; str[i] != '.'; i++)
    {
        if (str[i] == ')')
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (str[j] == '[')
                    return (0);
                if (str[j] == '(')
                {
                    str[i] = ' ';
                    str[j] = ' ';
                    break;
                }
            }
            if (str[i] != ' ')
                return (0);
        }
        else if (str[i] == ']')
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (str[j] == '(')
                    return (0);
                if (str[j] == '[')
                {
                    str[i] = ' ';
                    str[j] = ' ';
                    break;
                }
            }
            if (str[i] != ' ')
                return (0);
        }
    }
    return (1);
}

char *str_init(void)
{
    char *str;

    str = (char *)malloc(sizeof(char) * 105);
    for (int i = 0; i < 105; i++)
        str[i] = '\0';
    return (str);
}

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
    t_list *new = (t_list *)malloc(sizeof(t_list));
    new->content = content;
    new->next = NULL;

    return (new);
}

void ft_lstadd_back(t_list **node, t_list *new)
{
    t_list *last = *node;

    if (*node == NULL)
    {
        *node = new;
        return;
    }
    if (new == NULL)
        return;
    while (last->next != NULL)
        last = last->next;
    last->next = new;
}

void ret_print(t_list *ret)
{
    t_list *temp;

    while (ret)
    {
        printf("%s", (char *)ret->content);
        temp = ret;
        ret = ret->next;
        free(temp);
    }
}

void stack_init(char *stack)
{
    for (int i = 0; i < 100; i++)
        stack[i] = 0;
}

int top = -1;

void    push(char *stack, char c)
{
    stack[++top] = c;
}

void pop()
{
    --top;
}

int stack_push_pop(char *stack, char *str)
{

    for (int i = 0; str[i] != '.'; i++)
    {
        if (str[i] == '(' || str[i] == '[')
            push(stack, str[i]);
        else if (str[i] == ')')
        {
            if (top >= 0 && stack[top] == '(')
                pop();
            else
                return (0);
        }
        else if (str[i] == ']')
        {
            if (top >= 0 && stack[top] == '[')
                pop();
            else
                return (0);
        }
    }
    if (top == -1)
        return (1);
    else
        return (0);
    return (1);
}

int main()
{
    char *str;
    //char stack[100];
    t_list *ret = NULL;

    while (1)
    {
       // top = -1;
        //stack_init(stack);
        str = str_init();
        fgets(str, 105, stdin);
        //read(0, str, 103);
        // printf("%s\n", str);
        if (str[0] == '.') // && str[1] == '\n')
            break;
        // if (stack_push_pop(stack, str))
        //     ft_lstadd_back(&ret, ft_lstnew("yes\n"));
        // else
        //     ft_lstadd_back(&ret, ft_lstnew("no\n"));
        if (no_symmetry(str))
        {
            ft_lstadd_back(&ret, ft_lstnew("no\n"));
            continue;
        }
        if (balance_check(str))
            ft_lstadd_back(&ret, ft_lstnew("yes\n"));
        else
            ft_lstadd_back(&ret, ft_lstnew("no\n"));
        free(str);
    }
    free(str);
    ret_print(ret);
}