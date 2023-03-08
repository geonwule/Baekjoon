#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    char str[500001];
    char stack[500001] = {
        0,
    };
    int s_i = 0;
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
    {
        while (k > 0 && stack[s_i - 1] && stack[s_i - 1] < str[i])
        {
            k--;
            s_i--;
        }
        stack[s_i++] = str[i];
    }
    while (k-- > 0)
    {
        s_i--;
    }
    stack[s_i] = '\0';
    printf("%s\n", stack);
}
/* scanf n, k
str[n] scanf(%s)
k으ㅣ 수만큼 앞에서부터 삭제하여 -> 삭제한 숫자는 '-'로 바꿈
마지막에 출력할때 %c로 출력하면서 '-'는 건너뛰고 '\0'까지 출력.*/