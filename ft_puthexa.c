/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:22:58 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/15 16:48:38 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int hexa, char c)
{
	int		i;
	char	*lowx;
	char	*uppx;

	i = 0;
	lowx = "0123456789abcdef";
	uppx = "0123456789ABCDEF";
	if (hexa < 16)
	{
		if (c == 'x')
			ft_putchar_fd(lowx[hexa], 1);
		else
			ft_putchar_fd(uppx[hexa], 1);
		i++;
	}
	else
	{
		i++;
		i += ft_puthexa(hexa / 16, c);
		if (c == 'x')
			ft_putchar_fd(lowx[hexa % 16], 1);
		else
			ft_putchar_fd(uppx[hexa % 16], 1);
	}
	return (i);
}
