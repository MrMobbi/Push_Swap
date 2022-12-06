/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:41 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/06 15:47:15 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_tab	check;
	t_envi	env;
	t_envi	print;

	i = 0;
	if (ac == 1)
		return (0);
	ft_init_env(&env, &check, ac, av);
	if (ft_error(&env, &check, ac, av) == 1)
		return (0);
	ft_add_index(&check, &env);
	free(check.a);
	print = env;
	while (print.start_a->next != NULL)
	{
		printf("--------------\n");
		printf("value -> [%d]\n", print.start_a->value);
		printf("index -> [%d]\n", print.start_a->index);
		print.start_a = print.start_a->next;
	}
	printf("--------------\n");
	printf("value -> [%d]\n", print.start_a->value);
	printf("index -> [%d]\n", print.start_a->index);
	ft_quick_sort(&env);
	return (0);
}
