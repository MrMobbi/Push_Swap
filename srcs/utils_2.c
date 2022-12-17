/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:02:29 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/16 14:21:26 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_free_and_exit(t_envi *env, t_tab *check)
{
	ft_free_list(env->a);
	free(check->tab);
	exit(0);
}

void	ft_free(t_envi *env, t_tab *check)
{
	ft_free_list(env->a);
	free(check->tab);
}

void	ft_free_list(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int	ft_number_in_arg(char *str)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 1;
	check = 0;
	while (str[i] != '\0')
	{
		if (((str[i] >= '0' && str[i] <= '9') \
				|| (str[i] == '-' || str[i] == '+')) && str[i - 1] == ' ')
			check = 1;
		if (check == 1)
		{
			count++;
			check = 0;
		}
		i++;
	}
	return (count);
}
