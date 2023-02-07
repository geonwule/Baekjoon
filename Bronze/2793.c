#include <stdio.h>

int main()
{
    int a;

    scanf("%d", &a);
    for (int i = 0; i < 9; i++)
        printf("%d * %d = %d\n", a, i + 1, a * (i + 1));
}

// 2741

#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
        printf("%d\n", i + 1);
}

// 2753

#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);

    if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
        printf("1\n");
    else
        printf("0\n");
}

// 9498
#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    if (a >= 90)
        printf("A\n");
    else if (a >= 80)
        printf("B\n");
    else if (a >= 70)
        printf("C\n");
    else if (a >= 60)
        printf("D\n");
    else
        printf("F\n");
}

//10809
#include <stdio.h>
int main()
{
    char a[101];
    char tool[26];  //abcde....
    int box[26];
    for (int i = 0; i < 26; i++)
        box[i] = -1;
    scanf("%s", a);
    for (int i = 0; i < 26; i++)
    {
        tool[i] = 'a' + i;
        for (int j = 0; a[j] != '\0'; j++)
        {
            if (a[j] == tool[i])
            {
                box[i] = j;
                break ;
            }
        }
        printf("%d", box[i]);
        if (i + 1 != 26)
            printf(" ");
        else
            printf("\n");
    }
}

//  10869
#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n%d\n%d\n%d\n%d\n", a + b, a - b, a * b, a / b, a % b);
}

//  10950
#include <stdio.h>
int main()
{
    int n, a, b;
    int ret[10000];
    int max;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        ret[i] = a + b;
        max = i;
    }

    for (int i = 0; i <= max; i++)
        printf("%d\n", ret[i]);
}

// 10951
#include <stdio.h>
int main()
{
    int a, b;
    int ret[10000];
    int i = 0;
    while (1)
    {
        if (scanf("%d %d", &a, &b) == EOF)
            break ;
        ret[i] = a + b;
        i++;
    }
    for (int z = 0; z < i; z++)
        printf("%d\n", ret[z]);
}


// 10952
#include <stdio.h>
int main()
{
    int a, b;
    int ret[10000];
    int i = 0;
    while (1)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break ;
        ret[i] = a + b;
        i++;
    }
    for (int z = 0; z < i; z++)
        printf("%d\n", ret[z]);
}

// 11654
#include <stdio.h>
int main()
{
    char a;
    scanf("%c", &a);
    printf("%d\n", a - '0');
}

//
#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
}