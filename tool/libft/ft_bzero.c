/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:18:09 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/11 12:46:37 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i < len)
	{
		temp[i] = 0;
		i++;
	}
}
