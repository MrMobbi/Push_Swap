/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_error2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:20:17 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 11:31:49 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_illegal_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') && \
				(str[i + 1] == '-' || str[i + 1] == '+'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int(double *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] <= -2147483649.0 || tab[i] >= 2147483648.0)
			return (1);
		i++;
	}
	return (0);
}
