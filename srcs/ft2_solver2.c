/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_solver2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:03:33 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 14:10:46 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_2nbr(t_envi *env)
{
	if (ft_check_sort(env) == 1)
	{
		ft_rotate_a(env);
		ft_printf("ra\n");
	}
}

void	ft_solve_5nbr(t_envi *env)
{
	int	i;

	i = 1;
	while (i < 3)
	{
		if (env->a->idx == i)
		{
			ft_push_b(env);
			ft_printf("pb\n");
			i++;
		}
		else if (ft_search_path(env->a, i) <= 2)
		{
			ft_rotate_a(env);
			ft_printf("ra\n");
		}
		else
		{
			ft_reverse_a(env);
			ft_printf("rra\n");
		}
	}
	ft_solve_5nbr2(env);
}

void	ft_solve_5nbr2(t_envi *env)
{
	ft_solve_a(env);
	ft_push_a(env);
	ft_printf("pa\n");
	ft_push_a(env);
	ft_printf("pa\n");
}

int	ft_check_sort(t_envi *env)
{
	t_list	*tmp;
	int		check;

	tmp = env->a;
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

int	ft_lstlast_nbr(t_list *lst, int old)
{
	int		nbr;
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	nbr = tmp->idx;
	if (old < nbr)
		return (0);
	return (nbr);
}
