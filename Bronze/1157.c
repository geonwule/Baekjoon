#include <stdio.h>
#include <string.h>

int double_check(char *w, char c, int max)
{
    for (int i = 0; i < max; i++)
    {
        if (c == w[i])
            return (0);
    }
    return (1);
}

char many_check(char *w, char c, int idx, int *c_cnt, char many)
{
    char ret;
    int ret_c = 0;
    if (idx == 0 || double_check(w, c, idx))
        ret = c;
    else
        return (many);
    for (int i = 0; w[i] != '\0'; i++)
    {
        if (ret == w[i])
            ret_c++;
    }
    if (ret_c > *c_cnt)
    {
        *c_cnt = ret_c;
        return (ret);
    }
    else if (ret_c == *c_cnt)
    {
        return ('?');
    }
    else // ret_c < *c_cnt
        return (many);
}

int main()
{
    char word[1000001];
    char many;
    int many_c = 0;

    scanf("%s", word);
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
            word[i] -= 32;
    }
    for (int i = 0; word[i] != '\0'; i++)
    {
        many = many_check(word, word[i], i, &many_c, many);
    }
    printf("%c\n", many);
}