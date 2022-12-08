/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:36:53 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/07 17:29:57 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);

int		ft_putchar(char c);
int		ft_sort(va_list args, char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_put_unsinbr(unsigned int n);
int		ft_put_hexa(unsigned int nbr);
int		ft_put_uphexa(unsigned int nbr);
int		ft_put_address_hexa(unsigned long long nbr);

#endif
