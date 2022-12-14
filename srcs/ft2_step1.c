/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_solver3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:21:15 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 14:11:41 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_step1(t_envi *env)
{
	env->pi += env->chonk;
	while (env->len_a > 3)
	{
		if (env->index_chonk == env->pi)
		{
			env->pi += env->chonk;
			env->pi2 = env->pi - (env->chonk / 2);
		}
		if (env->a->idx <= env->limit && env->a->idx <= env->pi)
		{
			if (env->a->idx <= env->limit && env->a->idx <= env->pi2)
				ft_step1_pb_and_rb(env);
			else
				ft_step1_pb(env);
		}
		else
		{
			ft_rotate_a(env);
			ft_printf("ra\n");
		}
	}	
}

void	ft_step1_pb_and_rb(t_envi *env)
{
	ft_push_b(env);
	ft_rotate_b(env);
	env->index_chonk++;
	ft_printf("pb\nrb\n");
}

void	ft_step1_pb(t_envi *env)
{
	ft_push_b(env);
	env->index_chonk++;
	ft_printf("pb\n");
}
