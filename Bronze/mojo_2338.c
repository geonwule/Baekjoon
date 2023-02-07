#include <stdio.h>
#include <string.h>

char A[1002], B[1002];
int C[2345];

int compare(char *a, char *b)
{
	int al = strlen(a), bl = strlen(b), i;

	if(al == bl)
	{
		for(i = 0; i < al; i++)
		{
			if(a[i] != b[i])
				return a[i] > b[i] ? 1 : -1;
		}

		return 0;
	}
	else
		return al > bl ? 1 : -1;
}

void plus(char *a, char *b)
{
	int al = strlen(a), bl = strlen(b), k;

	C[0] = 0;

	for(k = 0; k < al && k < bl; k++)
	{
		C[k] += a[al - k - 1] - '0' + b[bl - k - 1] - '0';
		C[k + 1] = C[k]/10;
		C[k] %= 10;
	}

	while(k < al)
	{
		C[k] += a[al - k - 1] - '0';
		C[k + 1] = C[k]/10;
		C[k++] %= 10;
	}

	while(k < bl)
	{
		C[k] += b[bl - k - 1] - '0';
		C[k + 1] = C[k]/10;
		C[k++] %= 10;
	}

	if(C[k] == 0)
		k--;

	while(k >= 0)
		printf("%d", C[k--]);
}

void minus(char *a, char *b)
{
	int al = strlen(a), bl = strlen(b), k;

	C[0] = 0;

	for(k = 0; k < al && k < bl; k++)
	{
		C[k] += 10 + a[al - k - 1] - b[bl - k - 1];
		C[k + 1] = C[k]/10 - 1;
		C[k] %= 10;
	}

	while(k < al)
	{
		C[k] += 10 + a[al - k - 1] - '0';
		C[k + 1] = C[k]/10 - 1;
		C[k++] %= 10;
	}

	while(C[k] == 0)
		k--;

	while(k >= 0)
		printf("%d", C[k--]);
}

void multiply(char *a, char *b)
{
	int al = strlen(a) - 1, bl = strlen(b) - 1, i, j;

	for(i = 0; i < 2100; i++)
		C[i] = 0;

	for(i = 0; i <= al; i++)
		for(j = 0; j <= bl; j++)
			C[i + j] += (a[al - i] - '0')*(b[bl - j] - '0');

	for(i = 0; i < 2100; i++)
	{
		C[i + 1] += C[i]/10;
		C[i] %= 10;
	}

	while(C[i] == 0)
		i--;

	for(; i >= 0; i--)
		printf("%d", C[i]);
}

int main()
{
	char *a = A, *b = B, am = 0, bm = 0, c;
	
	scanf("%s %s", A, B);

	if(A[0] == '-')
	{
		a++;
		am++;
	}

	while(a[1] != 0 && a[0] == '0')
		a++;

	if(a[0] == '0')
		am = 0;

	if(B[0] == '-')
	{
		b++;
		bm++;
	}

	while(b[1] != 0 && b[0] == '0')
		b++;

	if(b[0] == '0')
		bm = 0;

	c = compare(a, b);

	if(am == bm)
	{
		if(a[0] == '0' && b[0] == '0')
			printf("0");
		else
		{
			if(am)
				printf("-");

			plus(a, b);
		}
	}
	else
	{
		if(c > 0)
		{
			if(am)
				printf("-");

			minus(a, b);
		}
		else if(c < 0)
		{
			if(bm)
				printf("-");

			minus(b, a);
		}
		else
			printf("0");
	}

	printf("\n");

	if(am != bm)
	{
		if(a[0] == '0' && b[0] == '0')
			printf("0");
		else
		{
			if(am)
				printf("-");

			plus(a, b);
		}
	}
	else
	{
		if(c > 0)
		{
			if(am)
				printf("-");

			minus(a, b);
		}
		else if(c < 0)
		{
			if(!bm)
				printf("-");

			minus(b, a);
		}
		else
			printf("0");
	}

	printf("\n");


	if(a[0] == '0' || b[0] == '0')
		printf("0");
	else
	{
		if((am + bm)%2)
			printf("-");

		multiply(a, b);
	}

	printf("\n");

	return 0;
}