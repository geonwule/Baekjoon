#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, a;
    char a_b[21];
    scanf("%d", &n);
    char *ret[n + 1];

    ret[n] = NULL;
    for (int i = 0; i < n; i++)
    {   
        char *temp;
        scanf("%d %s", &a, a_b);
        temp = malloc(strlen(a_b) * a + 1);
        temp[strlen(a_b) * a] = '\0';
        for (int j = 0; a_b[j] != '\0'; j++)
        {
            for (int k = 0 + j*a; k < a + j*a; k++)
            {
                temp[k] = a_b[j];
            }
        }
        ret[i] = temp;
    }
    for (int i = 0; ret[i] != 0; i++)
        printf("%s\n", ret[i]);
}