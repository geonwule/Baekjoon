#include <stdio.h>
#include <unistd.h>

int main()
{
    int d, p, n;
    scanf("%d", &n);
    d = 0;
	p = 0;
    for (int i = 0; i < n; i++)
    {
        char temp;
        read(0, &temp, 1);
        if (temp == 'D')
            d++;
        else
            p++;
		if (d - p == 2 || d - p == -2)
		{
			printf("%d:%d\n", d, p);
			return (0);
		}
    }
    printf("%d:%d\n", d, p);
}