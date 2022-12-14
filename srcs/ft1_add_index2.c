/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_add_index2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:00:46 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 13:02:24 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_pivot(double *list, int pivot)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = list[i];
	while (i < pivot)
	{
		if (list[i] > list[i + 1])
			return (0);
		i++;
	}
	return (1);
}
