#include <stdio.h>

int n;
int under_star;
char    ret[3073][6144];

void    one_star(void)
{
    printf("*");
}

int k_set(int temp)
{
    int k = 0;

    while (temp > 1)
    {
        temp /= 2;
        k++;
    }
    return (k);
}

void    print_star(int k, int star)
{
    int width = under_star * 5 + under_star - 1;
    int height = n;
    printf("k = %d\nstar_num = %d\nunder_star = %d\nwidth = %d\nheight = %d\n", k, star, under_star, width, height);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (y == 0)
            {
                if (y % 5 == 0)
                    ret[y][x] = ' ';
                else
                    ret[y][x] = '*';
            }
        }
        if (y == 0)
            ret[y][width] = '\n';
    }
}

int main()
{
    scanf("%d", &n);
    int temp = n / 3, k = k_set(temp) + 1; // 1 <= k <= 11
    under_star = n / 3;
    int star_num[11];
    star_num[1] = 1;
    for (int i = 2; i <= k; i++)
        star_num[i] = star_num[i - 1] * 3;
    print_star(k, star_num[k]);
}