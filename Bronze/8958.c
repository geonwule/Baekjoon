#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    char temp[81];
    scanf("%d", &a);
    int ret[a];
    int jum, con;
    for (int i = 0; i < a; i++)
    {
        scanf("%s", temp);
        jum = 0;
        con = 0;
        for (int j = 0; j < strlen(temp); j++)
        {
            if (j - 1 >= 0 && temp[j - 1] == 'O')
                con++;
            else
                con = 0;
            if (temp[j] == 'O')
                jum += 1 + con;
        }
        ret[i] = jum;
    }
    for (int i = 0; i < a; i++)
        printf("%d\n", ret[i]);
}