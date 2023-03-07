#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    char str[500001];
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i + 1 < n; i++)
    {
        if (k == 0)
            break;
        // if (i == 0)
        for (int j = i + 1; str[j] != '\0' && j < i + k; j++)
        {
            if (str[i] < str[j])
            {
                str[i] = '-';
                k--;
                break;
            }
        }
        // else if (str[i] < str[i + 1])
        // {
        //     str[i] = '-';
        //     k--;
        // }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] != '-')
            printf("%c", str[i]);
    }
}
/* scanf n, k
str[n] scanf(%s)
k으ㅣ 수만큼 앞에서부터 삭제하여 -> 삭제한 숫자는 '-'로 바꿈
마지막에 출력할때 %c로 출력하면서 '-'는 건너뛰고 '\0'까지 출력.*/