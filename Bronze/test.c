#include <stdio.h>

int main()
{
	int j = 0;
	for (int i = 0; i < 100; i++)
	{
		if (j >= 10)
			j = 0;
		printf("%d ", j++);
	}
}