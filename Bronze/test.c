#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if ((a >= 12 && a <= 16) && b == 0)
		printf("320");
	else
		printf("280");
	return (0);
}
