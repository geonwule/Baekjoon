#include <stdio.h>

int main()
{
    int a, sum = 0;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &a);
        sum += a * a;
    }
    printf("%d\n", sum % 10);
}

// 10871
#include <stdio.h>
int main()
{
    int n, x, t, j = 0;
    scanf("%d %d", &n, &x);
    int box[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (t < x)
        {
            box[j] = t;
            j++;
        }
    }
    for(int i = 0; i < j; i++)
    {
        if (i+1 != j)
            printf("%d\n", box[i]);
        else
            printf("%d ", box[i]);
    }
}