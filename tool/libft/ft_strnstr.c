/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:48:31 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/14 16:19:27 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	needle_check(const char *str, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while ((str[i + j] == nee[j]) && nee[j] != '\0' && i + j < len)
			j++;
		if (nee[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	index;

	index = needle_check(haystack, needle, len);
	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	if (len == 0 || index == -1)
		return (0);
	return ((char *)&haystack[index]);
}
