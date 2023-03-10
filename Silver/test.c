#include <stdio.h>
#include <stdlib.h>

int main()
{
	//char temp[20], temp2[20]; not equl

	char *temp = malloc(20), *temp2 = malloc(20);
	scanf("%s %s", temp, temp2);
	printf("%d\n%d\n", temp, temp2);
}