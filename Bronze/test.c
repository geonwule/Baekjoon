#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	char arr[150];
	scanf("%s", arr);
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
			arr[i] -= 32;
		else
			arr[i] += 32;
	}
	printf("%s", arr);
}