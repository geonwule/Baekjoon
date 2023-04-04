#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	int x;
	int y;
}	t_vars;

t_vars q[10];

int main()
{
	q[1].x = 5;
	q[1].y = -3;
	q[2].x = 9;
	q[2].y = 1;
	printf("%d\n%d\n", abs(q[1].x - q[2].x), abs(q[1].y - q[2].y));
}