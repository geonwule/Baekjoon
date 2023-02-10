#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
static int	digit_check(unsigned long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

static void	insert_int(char *ret, unsigned long long n, int len)
{
	len--;
	while (len >= 0)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(unsigned long long n)
{
	char	*ret;
	int		ret_len;
	
	if (n < 0)
		ret_len = digit_check(-n) + 1;
	else
		ret_len = digit_check(n);
	ret = (char *)malloc(sizeof(char) * ret_len + 1);
	if (ret == NULL)
		return (0);
	ret[ret_len] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		insert_int(ret + 1, -n, ret_len - 1);
	}
	else
		insert_int(ret, n, ret_len);
	return (ret);
}

unsigned long long jegob_31(int a)
{
    unsigned long long ret = 1;
    for (int i = 0; i < a; i ++)
    {
        ret *= 31;
    }
    return (ret);
}

int abcde_put(char c)
{
    int i = c - 96;
    return (i);
}
#include <limits.h>
int main()
{
    unsigned long long n = ULLONG_MAX+1;
    int ret = 0;

    printf("%llu\n%s\n", ULLONG_MAX+1, ft_itoa(n));
    // printf("%llu\n%llu\n%llu\n", jegob_31(50), jegob_31(50)*2, ULLONG_MAX);
}