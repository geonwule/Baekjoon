#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PLUS 0
#define MINUS 1

char a[20000]={0,}, b[20000]={0,};
char *ret;
int a_m=PLUS, b_m=PLUS, r_i=0,a_i,b_i;
char	*a_ptr, *b_ptr;

void	arg_init()
{
	scanf("%s %s", a, b);
	a_i=strlen(a);
	b_i=strlen(b);
	a_ptr = &a[0];
	b_ptr = &b[0];
	if(a[0]=='-')
	{
		a_m=MINUS;
		// a_i--;
		// a_ptr = &a[1];
	}
	if(b[0]=='-')
	{
		b_m=MINUS;
		// b_i--;
		// b_ptr = &b[1];
	}
}

char	*ft_a_m_b(char *pl_a, char *mi_b, int *flag)
{
	int pl_a_len = strlen(pl_a);
	int mi_b_len = strlen(mi_b) - 1;
	int i;
	if (mi_b_len > pl_a_len)
		*flag = MINUS;
	else if (mi_b_len == pl_a_len)
	{
		for (i = 0; pl_a[i] != 0 ; i++)
		{
			if (mi_b[i + 1] > pl_a[i])
			{
				*flag = MINUS;
				break ;
			}
		}
	}
	mi_b_len++;
	char *big, *small;
	int big_len, small_len;
	if (*flag == PLUS)
	{
		big = pl_a;
		big_len = pl_a_len - 1;
		small = mi_b;
		small_len = mi_b_len - 1;
	}
	else
	{
		big = mi_b;
		big_len = mi_b_len - 1;
		small = pl_a;
		small_len = pl_a_len - 1;
	}
	char	*r = calloc(20000, sizeof(char));
	for (i = 0; ;i++)
	{
		if (big_len - i < 0 && small_len - i < 0 \
			|| big_len - i < 0 && small[small_len - i] == '-' \
			|| small_len - i < 0 && big[big_len - i] == '-')
			break ;
		
		char	big_t, small_t;
		if (big_len - i < 0 || a[big_len - i] == '-')
			big_t = '0';
		else
			big_t = a[big_len - i];
		if (small_len - i < 0 || b[small_len - i] == '-')
			small_t = '0';
		else
			small_t = b[small_len - i];
		int r_int = big_t - small_t + '0';
		if (r_int < 0)
		{
			r[i] += r_int + ('9' + 1);
			r[i + 1] -= '1';
		}
		else
			r[i] += big_t - small_t + '0';
	}
	printf("%s\n", r);
	exit(0);
	return (r);
}

char	*ft_a_p_b(void)
{
	char	*r = calloc(20000, sizeof(char));
	int a_idx = a_i - 1, b_idx = b_i -1;
	int i;
	for (i = 0; ;i++)
	{
		if (a_idx - i < 0 && b_idx - i < 0 \
			|| a[a_idx - i] == '-' && b[b_idx - i] == '-' \
			|| (a_idx - i < 0 && b[b_idx - i] == '-') \
			|| (b_idx - i < 0 && a[a_idx - i] == '-'))
			break ;
		char a_t, b_t;
		if (a_idx - i < 0 || a[a_idx - i] == '-')
			a_t = '0';
		else
			a_t = a[a_idx - i];
		if (b_idx - i < 0 || b[b_idx - i] == '-')
			b_t = '0';
		else
			b_t = b[b_idx - i];
		r[i] += a_t + b_t - '0';
		if (r[i] > '9')
		{
			r[i] -= ('9' + 1);
			r[i + 1] += '1';
		}
	}
	return (r);
}

int main()
{
	int flag=PLUS;
	arg_init();
	if (!(a_m==PLUS && b_m ==MINUS \
		|| a_m==MINUS && b_m==PLUS))
	{
		ret=ft_a_p_b();
		if(a_m==MINUS&&b_m==MINUS)
			flag=MINUS;
	}
	else
	{
		if(a_m==MINUS)
			ft_a_m_b(b, a, &flag);
		else
			ft_a_m_b(a, b, &flag);
	}

	if(flag==MINUS)
	    printf("-");
	r_i = strlen(ret);
	while (--r_i >= 0)
		printf("%c", ret[r_i]);
}