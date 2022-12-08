/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:32:01 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/08 16:09:52 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_step1(t_envi *env);
void	ft_solve_a(t_envi *env);
int		ft_search_path(t_list *list);

int	ft_solver(t_envi *env)
{
	if (ft_check_sort(env) == 0)
		return (0);
	ft_step1(env);
	ft_solve_a(env);
	while (ft_check_sort(env) == 1 || env->st_b != NULL)
	{
		while (env->st_b->index != env->st_a->index - 1)
		{
			if (ft_search_path(env->st_b) >= env->chonk)
			{
				ft_rotate_b(env);
				ft_printf("rb\n");
			}
			else
			{
				ft_reverse_b(env);
				ft_printf("rrb\n");
			}
		}
		ft_push_a(env);
		ft_printf("pa\n");
	}
	return (0);
}

int	ft_search_path(t_list *list)
{
	int		i;
	t_list	*path;

	path = list;
	i = 0;
	while (path->next != NULL)
	{
		path = path->next;
		i++;
	}
	return (i);
}

void	ft_solve_a(t_envi *env)
{
	t_list	*check;
	while (ft_check_sort(env) == 1)
	{
		while (env->st_a->index != env->max_index)
		{
			ft_rotate_a(env);
			ft_printf("ra\n");
		}
		ft_rotate_a(env);
		ft_printf("ra\n");
		check = env->st_a->next;
		if (check->index != env->max_index - 1)
		{
			ft_swap_a(env);
			ft_printf("sa\n");
		}
	}
}

void	ft_step1(t_envi *env)
{
	env->pi += env->chonk;
	while (env->len_a > 3)
	{
		if (env->st_a->index <= env->limit && env->st_a->index <= env->pi)
		{
			if (env->st_a->index <= env->limit && env->st_a->index <= env->pi / 2)
			{
				ft_push_b(env);
				ft_rotate_b(env);
				ft_printf("pb\nrb\n");
			}
			else
			{
				ft_push_b(env);
				ft_printf("pb\n");
			}
		}
		else
		{
			ft_rotate_a(env);
			ft_printf("ra\n");
		}
	}	
}

int	ft_check_sort(t_envi *env)
{
	t_list	*tmp;
	int		check;

	tmp = env->st_a;
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
