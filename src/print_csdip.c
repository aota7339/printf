/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csdip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aota <aota@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:29:29 by aota              #+#    #+#             */
/*   Updated: 2022/06/23 15:29:32 by aota             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	return (write(1, &c, 1));
}

int	print_s(const char *str)
{
	if (!str)
		return (print_s("(null)"));
	return (write(1, str, (ft_strlen(str))));
}

int	print_di(long int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		print_c('-');
		n = (unsigned) ~ n + 1;
		++len;
	}
	if (n > 9)
	{
		len = len + print_di(n / 10);
		n = n % 10;
	}
	print_c(n + '0');
	return (++len);
}

static int	print_p_re(unsigned long long n)
{
	unsigned long int	un;
	int					len;

	un = n;
	len = 0;
	if (un >= 16)
	{
		len = len + print_p_re(un / 16);
	}
	print_c("0123456789abcdef"[un % 16]);
	return (++len);
}

int	print_p(void *n)
{
	unsigned long int	un;
	int					len;
	unsigned long int	castun;

	un = (uintptr_t)n;
	len = 0;
	if (un >= 16)
	{
		castun = un / 16;
		len = len + print_p_re(castun);
	}
	print_c("0123456789abcdef"[un % 16]);
	return (++len);
}
