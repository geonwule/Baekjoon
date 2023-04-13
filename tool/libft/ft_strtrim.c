/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:39:45 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/15 16:57:41 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(const char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		start;
	int		end;

	end = ft_strlen(s1) - 1;
	i = 0;
	while (i <= end && set_check(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	start = i;
	i = end;
	while (i >= 0 && set_check(s1[i], set))
		i--;
	end = i;
	new = (char *)malloc(sizeof(char) * end - start + 2);
	if (new == NULL)
		return (0);
	new[end - start + 1] = '\0';
	ft_strlcpy(new, s1 + start, end - start + 2);
	return (new);
}
