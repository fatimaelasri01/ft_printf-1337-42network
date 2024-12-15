/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:22:28 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/15 16:57:50 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexaa(unsigned long hexa)
{
	int		i;
	char	*lowx;

	i = 0;
	lowx = "0123456789abcdef";
	if (hexa < 16)
	{
		ft_putchar_fd(lowx[hexa], 1);
		i++;
	}
	else
	{
		i++;
		i += ft_puthexaa(hexa / 16);
		ft_putchar_fd(lowx[hexa % 16], 1);
	}
	return (i);
}

int	ft_putaddress(unsigned long p)
{
	int	c;

	c = 0;
	c += ft_putstr_fd("0x", 1);
	c += ft_puthexaa(p);
	return (c);
}
