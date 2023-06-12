#include <stdio.h>

void	h_print(void)
{
printf(" @@@   @@@ \n");
printf("@   @ @   @\n");
printf("@    @    @\n");
printf("@         @\n");
printf(" @       @ \n");
printf("  @     @  \n");
printf("   @   @   \n");
printf("    @ @    \n");
printf("     @     \n");
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		h_print();
}
