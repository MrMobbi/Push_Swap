/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_rotate_and_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:37:55 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 14:01:40 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_envi *env)
{
	t_list	*end;
	t_list	*tmp;

	tmp = env->a;
	end = env->a;
	while (end->next != NULL)
		end = end->next;
	end->next = env->a;
	env->a = env->a->next;
	tmp->next = NULL;
}

void	ft_rotate_b(t_envi *env)
{
	t_list	*end;
	t_list	*tmp;

	tmp = env->b;
	end = env->b;
	while (end->next != NULL)
		end = end->next;
	end->next = env->b;
	env->b = env->b->next;
	tmp->next = NULL;
}

void	ft_reverse_a(t_envi *env)
{
	t_list	*end;
	t_list	*before_end;

	end = env->a;
	while (end->next != NULL)
	{
		before_end = end;
		end = end->next;
	}
	end->next = env->a;
	env->a = end;
	before_end->next = NULL;
}

void	ft_reverse_b(t_envi *env)
{
	t_list	*end;
	t_list	*before_end;

	end = env->b;
	while (end->next != NULL)
	{
		before_end = end;
		end = end->next;
	}
	end->next = env->b;
	env->b = end;
	before_end->next = NULL;
}
