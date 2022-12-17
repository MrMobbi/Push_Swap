/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:38:36 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/17 15:42:29 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_read_ter(int fd, t_envi *env);
void	ft_compare_instruction(char *ter, t_envi *env);

int	main(int ac, char **av)
{
	t_tab	check;
	t_envi	env;

	if (ac < 2)
		exit(0);
	ft_init_env(&env, &check, ac, av);
	if (ft_error(&env, &check, ac, av) == 1)
		return (0);
	ft_read_ter(0, &env);
	if (ft_check_sort(&env) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

void	ft_read_ter(int fd, t_envi *env)
{
	char	*ter;

	ter = get_next_line(fd);
	while (ter)
	{
		ft_compare_instruction(ter, env);
		ter = get_next_line(fd);
	}
}

void	ft_compare_instruction(char *ter, t_envi *env)
{
	if (ft_strcmp(ter, "sa\n") == 0)
		ft_swap_a(env);
	else if (ft_strcmp(ter, "sb\n") == 0)
		ft_swap_b(env);
	else if (ft_strcmp(ter, "pa\n") == 0)
		ft_push_a(env);
	else if (ft_strcmp(ter, "pb\n") == 0)
		ft_push_b(env);
	else if (ft_strcmp(ter, "ra\n") == 0)
		ft_rotate_a(env);
	else if (ft_strcmp(ter, "rb\n") == 0)
		ft_rotate_b(env);
	else if (ft_strcmp(ter, "rra\n") == 0)
		ft_reverse_a(env);
	else if (ft_strcmp(ter, "rrb\n") == 0)
		ft_reverse_b(env);
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}
