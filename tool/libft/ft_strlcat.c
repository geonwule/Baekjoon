/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:40:16 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/11 18:30:26 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	result;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	result = dst_len + src_len;
	if (dstsize == 0 || dst_len >= dstsize)
		return (dstsize + src_len);
	if (dst_len < dstsize)
	{
		i = 0;
		while (dst_len + i < dstsize - 1 && src[i] != '\0')
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (result);
}
