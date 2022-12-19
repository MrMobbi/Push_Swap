/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft3_swap_and_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:39:50 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/17 19:16:42 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_swap_a(t_envi *env)
{
	if (env->a != NULL && env->a->next != NULL)
		ft_swap_a(env);
}

void	ft_check_swap_b(t_envi *env)
{
	if (env->b != NULL && env->b->next != NULL)
		ft_swap_b(env);
}

void	ft_check_ss(t_envi *env)
{
	if (env->b != NULL && env->b->next != NULL)
	{
		if (env->a != NULL && env->a->next != NULL)
		{
			ft_swap_a(env);
			ft_swap_b(env);
		}	
	}
}

void	ft_check_push_a(t_envi *env)
{
	if (env->b != NULL)
		ft_push_a(env);
}

void	ft_check_push_b(t_envi *env)
{
	if (env->a != NULL)
		ft_push_b(env);
}
