/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_solve_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:13:08 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 16:08:43 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_b(t_envi *env)
{
	while (ft_check_sort(env) == 1 || env->b != NULL)
	{
		while (env->b->idx != env->a->idx - 1 && env->b != NULL)
		{
			if (ft_search_path(env->b, env->a->idx - 1) < env->a->idx / 2)
				ft_push_under_a_rotate(env);
			else
				ft_push_under_a_reverse(env);
		}
		ft_push_a(env);
		ft_printf("pa\n");
		if (env->rotate > 0 && env->und_a == env->a->idx - 1)
		{
			while (env->a->idx - 1 == env->und_a && env->rotate > 0)
			{
				ft_reverse_a(env);
				ft_printf("rra\n");
				env->rotate--;
				env->und_a = ft_lstlast_nbr(env->a, env->und_a);
			}
		}
	}
}

void	ft_push_under_a_rotate(t_envi *env)
{
	if (env->b->idx < env->a->idx - 2 && env->b->idx > env->und_a)
	{
		env->und_a = env->b->idx;
		ft_push_a(env);
		ft_rotate_a(env);
		ft_printf("pa\nra\n");
		env->rotate++;
	}
	else
	{
		ft_rotate_b(env);
		ft_printf("rb\n");
	}
}

void	ft_push_under_a_reverse(t_envi *env)
{
	if (env->b->idx < env->a->idx - 2 && env->b->idx > env->und_a)
	{
		env->und_a = env->b->idx;
		ft_push_a(env);
		ft_rotate_a(env);
		ft_printf("pa\nra\n");
		env->rotate++;
	}
	else
	{
		ft_reverse_b(env);
		ft_printf("rrb\n");
	}
}
