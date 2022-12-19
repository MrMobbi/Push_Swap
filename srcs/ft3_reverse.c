/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft3_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:21:01 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/17 19:33:21 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_reverse_a(t_envi *env)
{
	if (env->a != NULL && env->a->next != NULL)
		ft_reverse_a(env);
}

void	ft_check_reverse_b(t_envi *env)
{
	if (env->b != NULL && env->b->next != NULL)
		ft_reverse_b(env);
}

void	ft_check_rrr(t_envi *env)
{
	if (env->b != NULL && env->b->next != NULL)
	{
		if (env->a != NULL && env->a->next != NULL)
		{
			ft_reverse_a(env);
			ft_reverse_b(env);
		}	
	}
}
