/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:38:45 by mjulliat          #+#    #+#             */
/*   Updated: 2022/10/26 12:32:38 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, str);
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += ft_sort(args, str[i + 1]);
			i += 2;
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}
