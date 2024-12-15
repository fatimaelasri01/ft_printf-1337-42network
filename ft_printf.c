/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:02:08 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/15 17:59:57 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_format(char c, va_list args, int *i)
{
	int	tmp;

	if (c == 'c')
		*i += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		*i += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'i' || c == 'd')
	{
		tmp = va_arg(args, int);
		ft_putnbr_fd(tmp, 1);
		*i += ft_nbrlen(tmp);
	}
	else if (c == 'u')
	{
		*i += ft_putunsigned(va_arg(args, unsigned int));
	}
	else if (c == 'p')
		*i += ft_putaddress(va_arg(args, unsigned long));
	else if (c == 'x' || c == 'X')
		*i += ft_puthexa(va_arg(args, unsigned int), c);
	else if (c == '%')
		*i += ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_format(format[i + 1], args, &count);
			i++;
		}
		else
			count += ft_putchar_fd(format[i], 1);
		if (format[i])
			i++;
	}
	va_end(args);
	return (count);
}
