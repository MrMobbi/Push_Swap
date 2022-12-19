/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:38:36 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/19 10:05:22 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	if (env.a == NULL)
	{
		ft_printf("KO\n");
		exit(0);
	}
	if (ft_check_sort(&env) == 0 && env.b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(&env, &check);
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
		ft_check_swap_a(env);
	else if (ft_strcmp(ter, "sb\n") == 0)
		ft_check_swap_b(env);
	else if (ft_strcmp(ter, "ss\n") == 0)
		ft_check_ss(env);
	else if (ft_strcmp(ter, "pa\n") == 0)
		ft_check_push_a(env);
	else if (ft_strcmp(ter, "pb\n") == 0)
		ft_check_push_b(env);
	else if (ft_strcmp(ter, "ra\n") == 0)
		ft_check_rotate_a(env);
	else if (ft_strcmp(ter, "rb\n") == 0)
		ft_check_rotate_b(env);
	else if (ft_strcmp(ter, "rr\n") == 0)
		ft_check_rr(env);
	else if (ft_strcmp(ter, "rra\n") == 0)
		ft_check_reverse_a(env);
	else if (ft_strcmp(ter, "rrb\n") == 0)
		ft_check_reverse_b(env);
	else if (ft_strcmp(ter, "rrr\n") == 0)
		ft_check_rrr(env);
	else
		ft_error_checker();
}
