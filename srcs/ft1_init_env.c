/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_init_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:59:53 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/16 13:38:03 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_env(t_envi *env, t_tab *check, int ac, char **av)
{
	t_list	*a;
	int		i;

	i = 0;
	if (ac == 2)
		ft_check_nbr_numbers(check, av);
	else
		check = ft_init_check(check, ac, av);
	a = ft_lstnew(check, i);
	i++;
	env->a = a;
	env->b = NULL;
	env->one_string = ft_number_in_arg(av[1]);
	env->max_index = check->len;
	env->len_a = check->len;
	env->limit = check->len - 3;
	env->pi = 0;
	env->pi2 = 0;
	ft_init_chonk(env);
	env->index_chonk = 0;
	env->rotate = 0;
	env->und_a = 0;
	ft_add_number_in_list(env, check, i);
}

void	ft_init_chonk(t_envi *env)
{
	if (env->max_index >= 0 && env->max_index <= 20)
		env->chonk = 10;
	else if (env->max_index >= 21 && env->max_index <= 60)
		env->chonk = 15;
	else if (env->max_index >= 61 && env->max_index <= 150)
		env->chonk = 25;
	else if (env->max_index >= 150 && env->max_index <= 300)
		env->chonk = 35;
	else if (env->max_index >= 301 && env->max_index <= 500)
		env->chonk = 49;
	else
		env->chonk = 70;
}

void	ft_check_nbr_numbers(t_tab *check, char **av)
{
	int	i;
	int	count;
	int	test;

	i = 0;
	count = 1;
	test = 0;
	while (av[1][i] != '\0')
	{
		if ((av[1][i] == '-' || av[1][i] == '+') && \
			(av[1][i + 1] < '0' || av[1][i + 1] > '9'))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (av[1][i] >= '0' && av[1][i] <= '9' && \
			(av[1][i - 1] == ' ' || av[1][i - 1] == '-' || av[1][i] == '+'))
				count++;
		i++;
	}
	if (count > 1)
		check = ft_one_string(av[1], check);
	else
		check = ft_init_check(check, 2, av);
}

void	ft_add_number_in_list(t_envi *env, t_tab *check, int i)
{
	t_list	*tmp;

	tmp = env->a;
	while (i < check->len)
	{
		tmp = ft_lstlast(tmp);
		tmp->next = ft_lstnew(check, i);
		i++;
	}
}

t_tab	*ft_init_check(t_tab *check, int ac, char **av)
{
	int	i;

	i = 1;
	check->len = ac - 1;
	check->tab = malloc(sizeof(double) * check->len);
	if (!check->tab)
		return (NULL);
	while (i < ac)
	{
		check->tab[i - 1] = ft_atod(av[i]);
		i++;
	}
	return (check);
}
