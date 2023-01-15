/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aota <aota@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:28:56 by aota              #+#    #+#             */
/*   Updated: 2022/07/04 11:38:43 by aota             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "ft_printf.h"

int	cs_jump(va_list ap, const char frm)
{
	size_t	len;

	len = 0;
	if (frm == 'c')
		len = len + print_c(va_arg(ap, int));
	else if (frm == 's')
		len = print_s(va_arg(ap, char *));
	else if (frm == '%')
		len = write(1, "%", 1);
	else if (frm == 'd' || frm == 'i')
		len = print_di(va_arg(ap, int));
	else if (frm == 'p')
	{
		len = print_s("0x");
		len = len + print_p(va_arg(ap, void *));
	}
	else if (frm == 'u')
		len = print_u(va_arg(ap, int));
	else if (frm == 'x')
		len = print_x(va_arg(ap, int));
	else if (frm == 'X')
		len = print_X(va_arg(ap, int));
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	len;
	size_t	i;
	va_list	ap;

	va_start(ap, fmt);
	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			len = len + cs_jump(ap, fmt[++i]);
			i++;
		}
		else
			len = len + print_c(fmt[i++]);
		if (len >= INT_MAX)
			return (-1);
	}
	va_end(ap);
	return ((int)len);
}
