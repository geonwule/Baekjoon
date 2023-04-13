/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:33:07 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/18 15:03:17 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_move(unsigned char *dp, unsigned char *sp, size_t len)
{
	size_t	i;

	i = 0;
	if (dp <= sp)
	{
		while (i < len)
		{
			dp[i] = sp[i];
			i++;
		}
	}
	else if (dp > sp)
	{
		while (len--)
			dp[len] = sp[len];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dp;
	unsigned char	*sp;

	dp = (unsigned char *)dest;
	sp = (unsigned char *)src;
	if (dest == 0 && src == 0)
		return (0);
	set_move(dp, sp, len);
	return ((void *)dp);
}
