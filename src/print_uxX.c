/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aota <aota@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:29:36 by aota              #+#    #+#             */
/*   Updated: 2022/06/23 15:29:37 by aota             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n > 9)
	{
		len = len + print_u(n / 10);
		n = n % 10;
	}
	print_c(n + '0');
	return (++len);
}

int	print_x(unsigned long long n)
{
	unsigned int	un;
	int				len;

	un = n;
	len = 0;
	if (un >= 16)
	{
		len = len + print_x(un / 16);
	}
	print_c("0123456789abcdef"[un % 16]);
	return (++len);
}

int	print_X(unsigned long long n)
{
	unsigned int	un;
	int				len;

	un = n;
	len = 0;
	if (un >= 16)
	{
		len = len + print_X(un / 16);
	}
	print_c("0123456789ABCDEF"[un % 16]);
	return (++len);
}
