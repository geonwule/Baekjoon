//
#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    char box[10000];
    scanf("%d", &a);
    scanf("%s", box);

    int box_len = strlen(box);
    int ret = 0;
    for (int i = 0; i < box_len; i++)
    {
        ret += box[i] - '0';
    }
    printf("%d\n", ret);
}