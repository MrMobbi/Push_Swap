/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft3_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:37:55 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/17 19:19:45 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_rotate_a(t_envi *env)
{
	if (env->a != NULL && env->a->next != NULL)
		ft_rotate_a(env);
}

void	ft_check_rotate_b(t_envi *env)
{
	if (env->b != NULL && env->b->next != NULL)
		ft_rotate_b(env);
}

void	ft_check_rr(t_envi *env)
{
	if (env->b != NULL && env->b->next != NULL)
	{
		if (env->a != NULL && env->a->next != NULL)
		{
			ft_rotate_a(env);
			ft_rotate_b(env);
		}	
	}
}
