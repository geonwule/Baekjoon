#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *a = malloc(2);
	char *b = malloc(2);
	scanf("%s %s", a, b);
	printf("%p\n%p\n", a, b);
}