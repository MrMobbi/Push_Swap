/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:32:01 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/06 18:53:49 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_envi *env);

int	ft_quick_sort(t_envi *env)
{
	t_envi	*print;

	printf("----- TEST FONCTION -----\n");
	if (ft_check_sort(env) == 0)
		return (0);
	ft_swap(&env->start_a);
	ft_push_a(env);
	ft_push_a(env);
	ft_push_a(env);
	ft_push_a(env);
	print = env;
	while (print->start_a->next != NULL)
	{
		printf("--------------\n");
		printf("value -> [%d]\n", print->start_a->value);
		printf("index -> [%d]\n", print->start_a->index);
		print->start_a = print->start_a->next;
	}
	printf("--------------\n");
	printf("value -> [%d]\n", print->start_a->value);
	printf("index -> [%d]\n", print->start_a->index);
	return (0);
}

int	ft_check_sort(t_envi *env)
{
	t_list	*tmp;
	int		check;

	tmp = env->start_a;
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
