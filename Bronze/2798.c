#include <stdio.h>

int main()
{
    int n, m, a, b, c, max;
    scanf("%d %d", &n, &m);
    int box[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &box[i]);
    a = box[0];
    b = box[1];
    c = box[2];
    max = a + b + c;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                a = box[i];
                b = box[j];
                c = box[k];
                if (max > m || (a + b + c <= m && a + b + c > max))
                    max = a + b + c;
            }
        }
    }
    printf("%d\n", max);
}