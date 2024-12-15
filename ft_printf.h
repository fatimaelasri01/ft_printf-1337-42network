/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:02:00 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/15 16:46:15 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_nbrlen(int nb);
int		ft_printf(const char *format, ...);
int		ft_puthexa(unsigned int hexa, char c);
int		ft_putaddress(unsigned long p);
int ft_putunsigned(unsigned int n);
size_t	ft_strlen(const char *s);
int	ft_putchar_fd(int c, int fd);
int	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif