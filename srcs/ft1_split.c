/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:41:39 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/05 17:08:30 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_word(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str[0] || !str)
		return (0);
	while (str[i + 1] != '\0')
	{
		if (str[i + 1] == c && str[i] != c)
			count++;
		i++;
	}
	if (str[i] != c)
		count++;
	return (count);
}

int	ft_strlen_c(const char *str, int index, char c)
{
	unsigned int	len;

	len = 0;
	while (str[index] != c && str[index] != '\0')
	{
		index++;
		len++;
	}
	return (len);
}

int	ft_find_next_word(const char *str, int index, char c)
{
	while (str[index] != c && str[index] != '\0')
		index++;
	while (str[index] == c && str[index] != '\0')
		index++;
	return (index);
}

char	**ft_split(char const *str, char c)
{
	int		index;
	int		i;
	char	**split;

	split = (char **)ft_calloc(ft_count_word(str, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	index = 0;
	i = 0;
	if (str[0] == c)
		index = ft_find_next_word(str, index, c);
	while (i < ft_count_word(str, c))
	{
		split[i] = ft_substr(str, index, ft_strlen_c(str, index, c));
		index = ft_find_next_word(str, index, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
