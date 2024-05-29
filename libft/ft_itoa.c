/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:22:12 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/16 13:56:12 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	count_digit(long *n, long	*is_negative)
{
	long	digit;
	long	num;

	digit = 1;
	*is_negative = 0;
	if (*n < 0)
	{
		*n *= -1;
		*is_negative = 1;
	}
	num = *n;
	while (num > 9)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

static long	ft_divit(long digit)
{
	long	div;

	div = 1;
	while (digit-- != 1)
		div *= 10;
	return (div);
}

static char	*ft_malloc(long is_negative, long digit)
{
	if (is_negative == 1)
		return ((char *)malloc(sizeof(char) * (digit + 2)));
	else
		return ((char *)malloc(sizeof(char) * (digit + 1)));
}

char	*ft_itoa(int n)
{
	char	*tmp;
	long	num;
	long	digit;
	long	is_negative;
	long	div;

	num = (long)n;
	digit = count_digit(&num, &is_negative);
	div = ft_divit(digit);
	tmp = ft_malloc(is_negative, digit);
	if (!tmp)
		return (NULL);
	digit = 0;
	if (is_negative == 1)
		tmp[digit++] = '-';
	while (div != 1)
	{
		tmp[digit++] = (num / div) + '0';
		num = num % div;
		div = div / 10;
	}
	tmp[digit++] = num + '0';
	tmp[digit] = '\0';
	return (tmp);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int n = -76220;

// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// }