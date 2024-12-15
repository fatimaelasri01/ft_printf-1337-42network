/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:33:32 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/15 16:58:10 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	c;

	c = 0;
	if (n < 10)
	{
		ft_putchar_fd(n + '0', 1);
		c++;
	}
	else
	{
		c += ft_putunsigned(n / 10);
		ft_putchar_fd((n % 10) + '0', 1);
		c++;
	}
	return (c);
}
