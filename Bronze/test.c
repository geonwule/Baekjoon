#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	printf("a > b = %lld\n", abs(INT_MIN));
}