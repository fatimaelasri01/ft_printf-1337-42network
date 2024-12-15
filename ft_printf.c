/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:02:08 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/15 14:57:29 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char c, va_list args, int i)
{
	char	*tmp;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, char), 1);
		i = 1;
	}
	if (c == 's')
	{
		tmp = va_arg(args, char *);
		ft_putstr_fd(tmp, 1);
		i = ft_strlen(tmp);
	}
	if (c == 'i' || c == 'u')
	{
		i = va_arg(args, int);
		ft_putnbr_fd(i, 1);
		i = ft_nbrlen(i);
	}
	if (c == 'p')
		i = ft_putaddress(va_arg(args, void *));
	if (c == 'x' || c == 'X')
		i = ft_puthexa(va_arg(args, void *), c);
	return (i);
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
			count += check_format(format[i + 1], args, count);
			if (format[i + 1] == '%')
				ft_putchar_fd(1, '%');
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
