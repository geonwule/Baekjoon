#include <stdio.h>
#include <string.h>
#define MAX 300000

int ret[MAX + 10] = {0};
int ret_i = 0;

void set_ab(void)
{
    char a[MAX + 1], b[MAX + 1];
    scanf("%s %s", a, b);
    int or_a_i = strlen(a) - 1, or_b_i = strlen(b) - 1;
    for (int a_i = or_a_i; a_i >= 0; a_i--)
    {
        int x = a[a_i] - '0';
        int i = 0;
        for (int b_i = or_b_i; b_i >= 0; b_i--)
        {
            int y = b[b_i] - '0';
            ret[ret_i + i] += (x * y) % 10;
            ret[ret_i + i + 1] += (x * y) / 10;
            if (ret[ret_i + i] >= 10)
            {
                ret[ret_i + i + 1] += ret[ret_i + i] / 10;
                ret[ret_i + i] %= 10;
            }
            i++;
        }
        ret_i++;
    }
}

int main()
{
    set_ab();
    int i = MAX + 9;
    while (ret[i] == 0)
        i--;
    for(i = i; i >= 0; i--)
    {
        printf("%d", ret[i]);
    }
}