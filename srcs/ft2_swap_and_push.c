/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_swap_and_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:39:50 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/07 17:28:36 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_envi *env)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = env->st_a->next;
	tmp2 = tmp1->next;
	tmp1->next = env->st_a;
	env->st_a->next = tmp2;
	env->st_a = tmp1;
}

void	ft_swap_b(t_envi *env)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = env->st_b->next;
	tmp2 = tmp1->next;
	tmp1->next = env->st_b;
	env->st_b->next = tmp2;
	env->st_b = tmp1;
}

void	ft_push_b(t_envi *env)
{
	t_list	*tmp;

	env->len_a--;
	if (env->st_b == NULL)
	{
		env->st_b = env->st_a;
		env->st_a = env->st_a->next;
		env->st_b->next = NULL;
	}
	else
	{
		if (env->st_a->next == NULL)
		{
			env->st_a->next = env->st_b;
			env->st_b = env->st_a;
			env->st_a = NULL;
		}
		else
		{
			tmp = env->st_a->next;
			env->st_a->next = env->st_b;
			env->st_b = env->st_a;
			env->st_a = tmp;
		}
	}
}

void	ft_push_a(t_envi *env)
{
	t_list	*tmp;

	if (env->st_a == NULL)
	{
		env->st_a = env->st_b;
		env->st_b = env->st_b->next;
		env->st_a->next = NULL;
	}
	else
	{
		if (env->st_b->next == NULL)
		{
			env->st_b->next = env->st_a;
			env->st_a = env->st_b;
			env->st_b = NULL;
		}
		else
		{
			tmp = env->st_b->next;
			env->st_b->next = env->st_a;
			env->st_a = env->st_b;
			env->st_b = tmp;
		}
	}
}
