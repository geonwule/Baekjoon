/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:16:17 by geonwule          #+#    #+#             */
/*   Updated: 2022/11/23 11:39:07 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	*word_set(char const *s, char c, int idx)
{
	char	*result;
	int		result_len;
	int		ori_idx;

	ori_idx = idx;
	while (s[idx] != '\0' && s[idx] != c)
		idx++;
	result_len = idx - ori_idx;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (0);
	result[result_len] = '\0';
	ft_strlcpy(result, s + ori_idx, result_len + 1);
	return (result);
}

static void	free_split(char **result, int j)
{	
	int	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	**ft_split2(char **result, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			result[j] = word_set(s, c, i);
			if (result[j] == NULL)
			{
				free_split(result, j);
				return (0);
			}
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		result_len;

	result_len = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (result_len + 1));
	if (result == NULL)
		return (0);
	result[result_len] = 0;
	return (ft_split2(result, s, c));
}
