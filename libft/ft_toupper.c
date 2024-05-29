/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:08:31 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/19 12:03:10 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
// 	char tmp = 'g';
// 	printf("%d\n", toupper((int)tmp));
// 	printf("%d\n", ft_toupper((int)tmp));

// 	return (0);
// }