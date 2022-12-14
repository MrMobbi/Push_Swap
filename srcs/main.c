/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:41 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/16 18:04:39 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_tab	check;
	t_envi	env;

	if (ac == 1)
		return (0);
	ft_init_env(&env, &check, ac, av);
	if (ft_error(&env, &check, ac, av) == 1)
		return (0);
	ft_add_index(&check, &env);
	ft_solver(&env);
	ft_free(&env, &check);
	return (0);
}
