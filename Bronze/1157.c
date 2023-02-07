#include <stdio.h>
#include <string.h>

int main()
{
    char word[1000001];
    char    many;

    scanf("%s", word);
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 32;
        }
    }
    for (int i = 0; i < strlen(word); i++)
    {
        if (i == 0)
        {
            many = word[i];
        }
    }
}