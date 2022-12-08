/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_one_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:48:53 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/08 16:45:33 by mjulliat         ###   ########.fr       */
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
	ft_free_one_string(new_av);
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
	check->len = count;
	check->tab = malloc(sizeof(double) * check->len);
	if (!check->tab)
		return (NULL);
	while (i < count)
	{
		check->tab[i] = ft_atod(av[i]);
		i++;
	}
	return (check);
}

void	ft_free_one_string(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
