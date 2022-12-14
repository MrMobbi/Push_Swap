/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:44:57 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/16 13:41:51 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_envi *env, t_tab *check, int ac, char **av)
{
	if (ft_check_error(env, ac, av) == 1)
	{
		write(2, "Error\n", 6);
		ft_free_and_exit(env, check);
	}
	if (ft_check_double(check->tab, check->len) == 1)
	{
		write(2, "Error\n", 6);
		ft_free_and_exit(env, check);
	}
	if (ft_check_int(check->tab, check->len) == 1)
	{
		write(2, "Error\n", 6);
		ft_free_and_exit(env, check);
	}
	return (0);
}

int	ft_check_error(t_envi *env, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (1);
	while (i < ac)
	{
		if (env->one_string == 1)
		{
			if (ft_number_in_arg(av[i]) > 1)
				return (1);
		}
		if (ft_check_arg(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_arg(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	if (ft_check_illegal_numbers(str) == 1)
		return (1);
	while ((str[i] > '9' || str[i] < '0') && str[i] != '\0')
		i++;
	check = ft_check_arg2(&str[i], check);
	if (check == 1)
		return (1);
	return (0);
}

int	ft_check_arg2(char *str, int check)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			check = 0;
		else if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
			check = 0;
		else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
			check = 0;
		else if (str[i] >= '0' && str[i] <= '9')
			check = 0;
		else
		{
			check = 1;
			break ;
		}
		i++;
	}
	return (check);
}

int	ft_check_double(double *tab, int len)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (i < len)
	{
		while (start < i)
		{
			if (tab[start] == tab[i])
				return (1);
			start++;
		}
		start = 0;
		i++;
	}
	return (0);
}
