#include <stdio.h>

int box[1001] = {
    0,
};

int main()
{
    int n, k, or_k, cnt = 0;
    scanf("%d %d", &n, &k);
    or_k = k;
    printf("<");
    printf("%d", k);
    box[k] = 1;
    cnt++;
    while (cnt < n)
    {
        printf(", ");
        for (int i = 0; i < or_k; i++)
        {
            k++;
            if (k > n)
                k -= n;
            while (box[k] == 1)
            {
                k++;
                if (k > n)
                    k -= n;
            }
        }
        while (box[k] == 1)
        {
            k -= 1;
            if (k == 0)
                k += n;
        }
        printf("%d", k);
        box[k] = 1;
        cnt++;
    }
    printf(">\n");
}