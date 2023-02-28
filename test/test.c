#include <stdio.h>
#include <unistd.h>

int main()
{
	char str[100];

	read(1, str, 100);
}
