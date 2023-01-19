/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:01:06 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/17 20:01:26 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	ret_len;
	unsigned int	i;

	ret_len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (ret == NULL)
		return (0);
	ret[ret_len] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
