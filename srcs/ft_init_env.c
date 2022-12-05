/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:59:53 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/05 18:26:49 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_env(t_envi *env, t_tab *check, int ac, char **av)
{
	t_list	*a;
	int		i;

	i = 0;
	if (ac == 2)
		ft_check_nbr_numbers(check, av[1]);
	else
		check = ft_init_check(check, ac, av);
	a = ft_lstnew(check, i);
	i++;
	env->start_a = a;
	env->start_b = NULL;
	env->count = 0;
	if (ac > 2)
		ft_add_number_in_list(env, check, i);
}

void	ft_check_nbr_numbers(t_tab *check, char *str)
{
	int	i;
	int	count;

	(void) check;
	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || \
				str[i] == '+') && str[-i - 1] == ' ')
			count ++;
		i++;
	}
	printf("count -> [%d]\n", count);
	if (count > 1)
	check = ft_one_string(str);
}

void	ft_add_number_in_list(t_envi *env, t_tab *check, int i)
{
	t_list	*tmp;

	tmp = env->start_a;
	while (i < check->len_a)
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
	check->len_a = ac - 1;
	check->a = malloc(sizeof(double) * check->len_a);
	if (!check->a)
		return (NULL);
	while (i < ac)
	{
		check->a[i - 1] = ft_atod(av[i]);
		i++;
	}
	return (check);
}
