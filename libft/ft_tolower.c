/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:08:35 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/19 12:02:32 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int main(void)
// {
// 	char tmp = 'H';
// 	printf("%d\n", tolower((int)tmp));
// 	printf("%d\n", ft_tolower((int)tmp));

// 	return (0);
// }