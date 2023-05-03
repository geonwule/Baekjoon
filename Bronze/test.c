#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 400000

char *multiply(char *a, char *b);
char *add(char *a, char *b);
char *subtract(char *a, char *b);

int main()
{
	char a[MAX_LEN + 1], b[MAX_LEN + 1];
	scanf("%s %s", a, b);

	char *result = multiply(a, b);
	printf("%s\n", result);
	free(result);
	return 0;
}

char *multiply(char *a, char *b)
{
	int n = strlen(a);
	int m = strlen(b);
	if (n == 0 || m == 0)
	{
		char *result = calloc(2, sizeof(char));
		result[0] = '0';
		result[1] = '\0';
		return result;
	}
	if (n == 1 && m == 1)
	{
		char *result = calloc(2, sizeof(char));
		result[0] = ((a[0] - '0') * (b[0] - '0')) + '0';
		result[1] = '\0';
		return result;
	}
	int half = (n > m ? n : m) / 2;
	char *a_left = a;
	char *a_right = a + half;
	char *b_left = b;
	char *b_right = b + half;

	char *p1 = multiply(a_left, b_left);
	char *p2 = multiply(a_right, b_right);
	char *p3 = multiply(add(a_left, a_right), add(b_left, b_right));
	char *p4 = subtract(subtract(p3, p1), p2);

	char *result = calloc(n + m + 1, sizeof(char));
	int i = 0;
	for (i = 0; i < strlen(p1); i++)
	{
		result[i] += p1[i] - '0';
	}
	for (i = 0; i < strlen(p2); i++)
	{
		result[i + 2 * half] += p2[i] - '0';
	}
	for (i = 0; i < strlen(p4); i++)
	{
		result[i + half] += p4[i] - '0';
	}
	// carry 처리
	for (i = 0; i < len1 + len2 - 1; i++)
	{
		if (result[i] >= 10)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	return (result);
}
=======
#include <string.h>
int main() {
	int ret=0;
	for(int i=1;i<=5;i++)
	{
		char arr[11];
		scanf("%s",arr);
		for(int j=0;arr[j]!='\0';j++)
		{
			if(strncmp("FBI",&arr[j],3)==0)
			{
				if(ret>0)
					printf(" ");
				printf("%d",i);
				ret++;
				break ;
			}
		}
	}
	if(ret==0)
		printf("HE GOT AWAY!");
}
>>>>>>> f4f335313d40b63972420c0cdfda8e6f4633d503
