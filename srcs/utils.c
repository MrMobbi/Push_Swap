/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:54:52 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/14 14:06:08 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_atod(char *str)
{
	int		i;
	int		neg;
	double	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		neg *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * neg);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_lstnew(t_tab *check, int i)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->value = check->tab[i];
	new->idx = 0;
	new->next = NULL;
	return (new);
}

char	*ft_substr(char const *str, size_t start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (start > ft_strlen(str))
	{
		cpy = malloc(sizeof(char) * 1);
		if (!cpy)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	cpy = malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (i < len && str[start] != '\0')
	{
		cpy[i] = str[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*cal;
	size_t	i;

	i = 0;
	cal = malloc(count * size);
	if (!cal)
		return (0);
	while (i < count * size)
	{
		cal[i] = 0;
		i++;
	}
	return (cal);
}
