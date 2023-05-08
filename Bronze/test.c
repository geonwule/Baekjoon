#include <stdio.h>
#include <unistd.h>

int main()
{
    int z,x,c,v,b,n;
	scanf("%d %d %d %d %d %d", &z, &x, &c, &v, &b, &n);
	printf("%d %d %d %d %d %d\n", 1-z, 1-x, 2-c, 2-v, 2-b, 8-n);
}