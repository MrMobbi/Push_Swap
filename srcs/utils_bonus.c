/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:56:55 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/17 15:18:20 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (s1[i] != s2[i] || s2[i] != '\0')
	{
		if (s1[i] < s2[i] || s1[i] > s2[i])
		{
			sum = s1[i] - s2[i];
			return (sum);
		}
		else
			sum = 0;
		i++;
	}
	return (sum);
}
