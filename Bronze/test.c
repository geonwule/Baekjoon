#include <stdio.h>
#include <stdlib.h>

int *temp_set(int *a, int a_len)
{
	int *temp;

	temp = (int *)malloc(sizeof(int) * 2002);
	for (int i = 0; i < 2002; i++)
	{
		if (i < a_len)
			temp[i] = a[i];
		else
			temp[i] = 0;
	}
	return (temp);
}

int a_mod_b(int *a, int *b, int a_len, int b_len, int *c_len)
{
	int *c = temp_set(a, a_len);
	int a_s = 0, b_s = 0, i, j;

	for (j = 0; j < b_len; j++)
	{
		b_s = b_s * 10 + b[j];
		a_s = a_s * 10 + a[j];
	}
	if (b_s > a_s)
	{
		a_s = a_s * 10 + a[j + 1];
	}
}

int main()
{
	int a_len = 6, b_len = 2, c_len;
	int a[6], b[2], *c;
	a = {3, 8, 2, 5, 1, 2};
	b = {3, 9};

	c = a_mod_b(a, b, a_len, b_len, &c_len);
	for (int i = 0; i < c_len; i++)
	{
		printf("%d", c[i]);
	}
	printf("\n");
}