/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:42:00 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/17 19:00:54 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_check(int n)
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

static void	insert_int(char *ret, int n, int len)
{
	len--;
	while (len >= 0)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		ret_len;

	if (n == -2147483648)
	{
		ret = ft_strdup("-2147483648");
		return (ret);
	}
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
