/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:48:53 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/06 10:52:36 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tab	*ft_one_string(char *str, t_tab *check)
{
	char	**new_av;
	int		count;

	new_av = ft_split(str, ' ');
	count = ft_count_numbers(new_av);
	check = ft_init_check_one(check, count, new_av);
	return (check);
}

int	ft_count_numbers(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

t_tab	*ft_init_check_one(t_tab *check, int count, char **av)
{
	int	i;

	i = 0;
	check->len_a = count;
	check->a = malloc(sizeof(double) * check->len_a);
	if (!check->a)
		return (NULL);
	while (i < count)
	{
		check->a[i] = ft_atod(av[i]);
		i++;
	}
	return (check);
}
