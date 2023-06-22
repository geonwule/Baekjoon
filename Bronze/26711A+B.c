#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	return 0;
}

int	ft_abs(char *a, char *b)
{
	int a_i = strlen(a);
	int b_i = strlen(b);
	if (a_i > b_i)
		return 1;
	else if (a_i < b_i)
		return -1;
	else // a_i == b_i
	{
		int i = 0;
		while (i < a_i)
		{
			int a_int = a[i] - '0';
			int b_int = b[i] - '0'; 
			int comp_a_b = compare(a_int, b_int);
			if (comp_a_b > 0)
				return 1;
			else if (comp_a_b < 0)
				return -1;
			else
			{
				i++;
				continue ;
			}
		}
	}
	return 0; //a == b
}

int	a_minus_b(char *a, char *b, char *c, int a_i, int b_i)
{
	int	i;
	for (i = 0; a_i - i >= 0 && b_i - i >= 0; i++)
	{
		int a_int = a[a_i - i] - '0';
		int b_int = b[b_i - i] - '0';
		if (a_int - b_int >= 0)
		{
			c[i] += a_int - b_int;
		}
		else // ex 12 - 3
		{
			for (int j = a_i - i - 1; j >= 0; j--)
			{
				if (a[j] > '0')
				{
					a[j] -= 1;						  // minus -1
					for (j = j + 1; j < a_i - i; j++) // input 9
						a[j] += 9;
					c[i] += a_int - b_int + 10;
					break;
				}
			}
		}
	}
	while (a_i - i >= 0)
	{
		c[i] += a[a_i - i] - '0';
		i++;
	}
	return (i);
}

int main()
{
	char tmp_a[10050], tmp_b[10050], c[10050];
	memset(c, '0', 10050);
	scanf("%s %s", tmp_a, tmp_b);

	int a_m = 0, b_m = 0;
	char *a = &tmp_a[0], *b = &tmp_b[0];
	if (tmp_a[0] == '-')
	{
		a_m = 1;
		a = &tmp_a[1];
	}
	if (tmp_b[0] == '-')
	{
		b_m = 1;
		b = &tmp_b[1];
	}

	int a_i = strlen(a) - 1;
	int b_i = strlen(b) - 1;

	int i;
	if ((!a_m && !b_m) || (a_m && b_m)) // -a - b || a + b
	{
		for (i = 0; a_i - i >= 0 && b_i - i >= 0; i++)
		{
			c[i] += a[a_i - i] - '0' + b[b_i - i] - '0';
			if (c[i] > '9')
			{
				c[i] -= 10;
				c[i + 1] += 1;
			}
		}
		while (a_i - i >= 0)
		{
			c[i] += a[a_i - i] - '0';
			if (c[i] > '9')
			{
				c[i] -= 10;
				c[i + 1] += 1;
			}
			i++;
		}
		while (b_i - i >= 0)
		{
			c[i] += b[b_i - i] - '0';
			if (c[i] > '9')
			{
				c[i] -= 10;
				c[i + 1] += 1;
			}
			i++;
		}
	}
	else // a - b || -a + b
	{
		// compare(9, -5);
		//  (abs(a > 0) > abs(b < 0))
		//  a_m = 0;, b_m = 0;
		if (a_m && !b_m) // -a + b
		{
			char	*temp;
			int		temp_i;
			temp = a;
			temp_i = a_i;
			a = b;
			a_i = b_i;
			b = temp;
			b_i = temp_i; // swap
		}
		// else(!a_m && b_m) .. a - b 
		if (ft_abs(a, b) > 0)
		{
			a_m = 0;
			b_m = 0;
			i = a_minus_b(a, b, c, a_i, b_i);
		}
		else if (ft_abs(a, b) < 0)
		{
			i = a_minus_b(b, a, c, b_i, a_i);
		}
		else // a == b
		{
			printf("0");
			return (0);
		}
	}

	while (i > 0 && c[i] == '0')
		i--;
	// print
	if (a_m || b_m)
		printf("-");
	while (i >= 0)
	{
		printf("%c", c[i]);
		i--;
	}
}
