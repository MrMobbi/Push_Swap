/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_add_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:19:21 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 14:06:59 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_index(t_tab *check, t_envi *env)
{
	ft_quick_sort(check->tab, 0, check->len - 1);
	ft_index_to_list(check, env);
}

void	ft_index_to_list(t_tab *check, t_envi *env)
{
	t_list	*tmp;
	int		i;

	tmp = env->a;
	i = 0;
	while (i < check->len)
	{
		ft_index(env->a, i, check->tab[i]);
		i++;
	}
}

void	ft_index(t_list *lst, int i, double nbr)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		if (tmp->value == nbr)
			tmp->idx = i + 1;
		tmp = tmp->next;
	}
	if (tmp->value == nbr)
		tmp->idx = i + 1;
}

void	ft_quick_sort(double *list, int start, int pivot)
{
	double	tmp;
	int		j;
	int		i;

	j = start;
	i = j - 1;
	tmp = ft_quick_sort2(list, &i, &j, pivot);
	i++;
	tmp = list[j];
	list[j] = list[i];
	list[i] = tmp;
	if (pivot - start > 0)
	{
		ft_quick_sort(list, 0, i - 1);
		if (ft_check_pivot(list, pivot) == 0)
			ft_quick_sort(list, i + 1, pivot);
	}
}

double	ft_quick_sort2(double *list, int *i, int *j, int pivot)
{
	double	tmp;

	tmp = 0;
	while (*j < pivot)
	{
		if (list[*j] < list[pivot])
		{
			(*i)++;
			tmp = list[*j];
			list[*j] = list[*i];
			list[*i] = tmp;
		}
		(*j)++;
	}
	return (tmp);
}
