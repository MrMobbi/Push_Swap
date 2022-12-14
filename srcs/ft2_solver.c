/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:32:01 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 16:15:02 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_solver(t_envi *env)
{
	if (ft_check_sort(env) == 0)
		return (0);
	if (env->max_index == 2)
	{
		ft_solve_2nbr(env);
		return (0);
	}
	if (env->max_index == 5)
	{
		ft_solve_5nbr(env);
		return (0);
	}
	ft_step1(env);
	ft_solve_a(env);
	ft_solve_b(env);
	return (0);
}

int	ft_search_path(t_list *list, int value)
{
	int		i;
	t_list	*path;

	path = list;
	i = 0;
	while (1)
	{
		if (path == NULL)
			return (i);
		if (path->idx == value)
			break ;
		path = path->next;
		i++;
	}
	return (i);
}

void	ft_solve_a(t_envi *env)
{
	t_list	*check;
	int		i;

	i = env->max_index;
	while (ft_check_sort(env) == 1)
	{
		while (env->a->idx != env->max_index)
		{
			if (ft_search_path(env->a, i) < 2)
				ft_print_ra(env);
			else
				ft_print_rra(env);
		}
		ft_print_ra(env);
		check = env->a->next;
		if (check->idx != env->max_index - 1)
		{
			ft_swap_a(env);
			ft_printf("sa\n");
		}
	}
}

void	ft_print_ra(t_envi *env)
{
	ft_rotate_a(env);
	ft_printf("ra\n");
}

void	ft_print_rra(t_envi *env)
{
	ft_reverse_a(env);
	ft_printf("rra\n");
}
