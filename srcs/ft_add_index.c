/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:19:21 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/05 13:35:00 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_index(t_tab *check, t_envi *env)
{
	ft_sort_check(check->a, 0, check->len_a - 1);
	ft_index_to_list(check, env);
}

void	ft_index_to_list(t_tab *check, t_envi *env)
{
	t_list	*tmp;
	int		i;
	
	tmp = env->start_a;
	i = 0;
	while (i < check->len_a)
	{
		ft_index(env->start_a, i, check->a[i]);
		i++;
	}
}

void	ft_index(t_list *lst, int i, double nbr)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		if (tmp->value == nbr)
			tmp->index = i + 1;
		tmp = tmp->next;
	}
	if (tmp->value == nbr)
		tmp->index = i + 1;
}

void	ft_sort_check(double *list, int start, int pivot)
{
	double	tmp;
	int		j;
	int		i;

	j = start;
	i = j -1;
	tmp  = 0;
	while (j < pivot)
	{
		if (list[j] <  list[pivot])
		{
			i++;
			tmp = list[j];
			list[j] = list[i];
			list[i] = tmp;
		}
		j++;
	}
	i++;
	tmp = list[j];
	list[j] = list[i];
	list[i] = tmp;
	if (pivot - start > 2)
	{
		ft_sort_check(list, 0, i- 1);
		ft_sort_check(list, i + 1, pivot);
	}
}
