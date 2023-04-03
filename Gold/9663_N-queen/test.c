#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = abs(5 - 3);
	int b = abs (3 - 5);
	if (a == b)
		printf("abs(5 - 3) == (abs 3 - 5)\na = %d\nb = %d\n", a, b);//printf("abs(-5 + 2) = %d\n", abs(2 - 5));
}