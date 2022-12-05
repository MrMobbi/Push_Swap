/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:41 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/05 13:30:09 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_tab	check;
	t_envi	env;

	i = 0;
	ft_init_env(&env, &check, ac, av);
	if (ft_error(&check, ac, av) == 1)
		return (0);
	ft_add_index(&check, &env);
	while (env.start_a->next != NULL)
	{
		printf("--------------\n");
		printf("value -> [%d]\n", env.start_a->value);
		printf("index -> [%d]\n", env.start_a->index);
		env.start_a = env.start_a->next;
	}
	printf("--------------\n");
	printf("value -> [%d]\n", env.start_a->value);
	printf("index -> [%d]\n", env.start_a->index);
	free(check.a);
	ft_quick_sort(&env);
	return (0);
}
