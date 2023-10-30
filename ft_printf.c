/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tklein <tklein@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:41:44 by tklein            #+#    #+#             */
/*   Updated: 2023/10/29 23:16:56 by tklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_pointer(va_arg(ap, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_hexlow(va_arg(ap, int)));
	else if (c == 'X')
		return (ft_hexupp(va_arg(ap, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, str);
	count = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
			count += ft_print_format(str[++i], ap);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
