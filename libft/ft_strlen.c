/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:07:09 by hmorisak          #+#    #+#             */
/*   Updated: 2022/10/16 19:41:29 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (*c != '\0')
	{
		len++;
		c++;
	}
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char c[] = "hello world";

// 	printf("%zu\n", ft_strlen(c));
// 	return (0);
// }