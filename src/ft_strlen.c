/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aota <aota@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:12:23 by aota              #+#    #+#             */
/*   Updated: 2022/06/05 23:14:11 by aota             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*

int	main(void)
{
	const char	*str;
	size_t		i; 

	str = "HelloWorld";
	i = ft_strlen(str);
	printf ("%zu\n", i);
	return (0);
}*/
