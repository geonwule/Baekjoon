#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 암호는 알파벳 소문자로만 구성
// 암호는 최소 1개의 모음(a e i o u)
// 최소 2개의 자음으로 구성
// 알파벳이 증가하는 순서로 배열 추측(아스키상)
// ex) a b c -> ok ,  b a c -> no

// 알파벳 길이 : L
// 알파벳 종류 갯수 : C
// 3 <= L <= C <= 15
// 각줄에 하나씩 사전식으로 가능성 있는 암호 모두 출력

// 최대 L = 15, C = 15 -> 
// 최대 답의 갯수  15! = 1307674368000 (대략 13조)

char ret[16], moeum[15], jaeum[15];

int compare(const void *x, const void *y)
{
    char a = *(char *)x;
    char b = *(char *)y;
    return (a - b);
}

void    C_init(int n)
{
    int mo_c = 0, ja_c = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp == 'a' || temp == 'e' || temp == 'i'
            || temp == 'o' || temp == 'u')
        {
            moeum[mo_c++] = (char)temp;
        }
        else
            jaeum[ja_c++] = (char)temp;
    }
    qsort(moeum, mo_c, sizeof(char), compare);
    qsort(jaeum, ja_c, sizeof(char), compare);
}

// char ret[16], moeum[15] jaeum[15]
int main()
{
    int L, C;
    scanf("%d %d", &L, &C);
    C_init(C);

}