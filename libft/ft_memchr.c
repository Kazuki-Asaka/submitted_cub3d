/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:05:58 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/17 15:29:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	src;

	dst = (unsigned char *)s;
	src = (unsigned char)c;
	while (n--)
	{
		if (*dst == src)
			return (dst);
		dst++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};

// 	// printf("%s\n", memchr(s, 0, 1));
// 	printf("%s\n", ft_memchr(s, 0, 1));

// 	return (0);
// }
