/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_swap_and_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:39:50 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 14:03:21 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_envi *env)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = env->a->next;
	tmp2 = tmp1->next;
	tmp1->next = env->a;
	env->a->next = tmp2;
	env->a = tmp1;
}

void	ft_swap_b(t_envi *env)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = env->b->next;
	tmp2 = tmp1->next;
	tmp1->next = env->b;
	env->b->next = tmp2;
	env->b = tmp1;
}

void	ft_push_b(t_envi *env)
{
	t_list	*tmp;

	env->len_a--;
	if (env->b == NULL)
	{
		env->b = env->a;
		env->a = env->a->next;
		env->b->next = NULL;
	}
	else
	{
		if (env->a->next == NULL)
		{
			env->a->next = env->b;
			env->b = env->a;
			env->a = NULL;
		}
		else
		{
			tmp = env->a->next;
			env->a->next = env->b;
			env->b = env->a;
			env->a = tmp;
		}
	}
}

void	ft_push_a(t_envi *env)
{
	t_list	*tmp;

	if (env->a == NULL)
	{
		env->a = env->b;
		env->b = env->b->next;
		env->a->next = NULL;
	}
	else
	{
		if (env->b->next == NULL)
		{
			env->b->next = env->a;
			env->a = env->b;
			env->b = NULL;
		}
		else
		{
			tmp = env->b->next;
			env->b->next = env->a;
			env->a = env->b;
			env->b = tmp;
		}
	}
}
