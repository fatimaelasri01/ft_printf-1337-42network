/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:22:28 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/15 15:00:44 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned int p)
{
	int	c;

	c = 0;
	ft_putstr_fd("0x", 1);
	c = ft_puthexa(p, 'x');
	return (c);
}