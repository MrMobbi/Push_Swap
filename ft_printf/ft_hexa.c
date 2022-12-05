/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:07:54 by mjulliat          #+#    #+#             */
/*   Updated: 2022/10/26 12:19:02 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_address_hexa(unsigned long long nbr)
{
	static int	count;

	count = 0;
	if (nbr > 15)
	{
		ft_put_address_hexa(nbr / 16);
		nbr = nbr % 16;
	}
	if (nbr >= 0 && nbr <= 9)
		count += ft_putchar(nbr + '0');
	if (nbr >= 10 && nbr <= 15)
		count += ft_putchar(nbr + 87);
	return (count);
}

int	ft_put_hexa(unsigned int nbr)
{
	static int	count;

	count = 0;
	if (nbr > 15)
	{
		ft_put_hexa(nbr / 16);
		nbr = nbr % 16;
	}
	if (nbr >= 0 && nbr <= 9)
		count += ft_putchar(nbr + '0');
	if (nbr >= 10 && nbr <= 15)
		count += ft_putchar(nbr + 87);
	return (count);
}

int	ft_put_uphexa(unsigned int nbr)
{
	static int	count1;

	count1 = 0;
	if (nbr > 15)
	{
		ft_put_uphexa(nbr / 16);
		nbr = nbr % 16;
	}
	if (nbr >= 0 && nbr <= 9)
		count1 += ft_putchar(nbr + '0');
	if (nbr >= 10 && nbr <= 15)
		count1 += ft_putchar(nbr + 55);
	return (count1);
}
