/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:39:50 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/06 18:59:05 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *list;
	tmp2 = (*list)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*list = tmp2;
}

void	ft_push_a(t_envi *env)
{
	t_list	*tmp;

	if (env->start_b == NULL)
	{
		env->start_b = env->start_a;
		env->start_a = env->start_a->next;
		env->start_b->next = NULL;
	}
	else
	{
		if (env->start_a->next == NULL)
		{
			env->start_a->next = env->start_b;
			env->start_b = env->start_a;
			env->start_a = NULL;
		}
		else
		{
			tmp = env->start_a->next;
			env->start_a->next = env->start_b;
			env->start_b = env->start_a;
			env->start_a = tmp;
		}
	}
}

void	ft_push_b(t_envi *env)
{
	t_list	*tmp;

	if (env->start_a == NULL)
	{
		env->start_a = env->start_b;
		env->start_b = env->start_b->next;
		env->start_a->next = NULL;
	}
	else
	{
		if (env->start_b->next == NULL)
		{
			env->start_b->next = env->start_a;
			env->start_a = env->start_b;
			env->start_b = NULL;
		}
		else
		{
			tmp = env->start_b->next;
			env->start_b->next = env->start_a;
			env->start_a = env->start_b;
			env->start_b = tmp;
		}
	}
}
