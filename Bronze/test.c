#include <stdio.h>

int main()
{
	int i = 0;
	while (1)
	{
		char t;
		int status = scanf("%c", &t);
		if (status == EOF)
			break ;
		if (t == '\n' || t == '\0')
			i++;
	}
	printf("%d", i);
}