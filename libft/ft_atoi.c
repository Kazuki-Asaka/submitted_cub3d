/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:39:58 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/18 11:22:29 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_flow(long sum, char c, int flag)
{
	if (LONG_MAX / 10 < sum && c && flag == 0)
		return (1);
	if (sum == LONG_MAX / 10 && LONG_MAX % 10 < c - '0' && flag == 0)
		return (1);
	if (LONG_MIN / 10 > -sum && c && flag == 1)
		return (-1);
	if (LONG_MIN / 10 == -sum && LONG_MIN % 10 > -(c - '0') && flag == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		flag;
	long	sum;

	flag = 0;
	sum = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = 1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
		if (check_flow(sum, *str, flag) > 0)
			return ((int)LONG_MAX);
		if (check_flow(sum, *str, flag) < 0)
			return ((int)LONG_MIN);
	}
	if (flag == 1)
		sum *= -1;
	return ((int)sum);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	const char str[] = "9223372036854775808";
// 	printf("%d\n", atoi(str));
// 	printf("%d\n", ft_atoi(str));
// 	// printf("%lu\n", (int)LONG_MIN);

// 	return (0);
// }
