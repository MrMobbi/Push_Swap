/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:32:01 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/05 11:18:25 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_envi *env);

int	ft_quick_sort(t_envi *env)
{
	if (ft_check_sort(env) == 0)
		return (0);
	return (0);
}

int	ft_check_sort(t_envi *env)
{
	t_list	*tmp;
	int		check;

	tmp = env->start_a;
	check = tmp->value;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->value < check)
			return (1);
		check = tmp->value;
	}
	return (0);
}
