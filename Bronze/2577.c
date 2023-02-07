#include <stdio.h>

int main()
{
    int a, b, c;
    int box[10];
    int ret[10];
    for (int i = 0; i < 10; i++)
    {
        ret[i] = 0;
        box[i] = i;
    }
    scanf("%d %d %d", &a,&b,&c);
    int gob = a * b * c;
    int temp;
    for (int j = 0; j < 10; j++)
    {
        temp = gob;
        while (temp)
        {
            if (temp % 10 == box[j])
                ret[j]++;
            temp /= 10;
        }
    }
    for (int i = 0; i < 10; i++)
        printf("%d\n", ret[i]);
}