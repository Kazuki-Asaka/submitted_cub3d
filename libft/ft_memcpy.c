/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:35:03 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/16 16:17:37 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	if (dst || src)
	{
		dstcpy = (unsigned char *)dst;
		srccpy = (unsigned char *)src;
		while (n)
		{
			*dstcpy = *srccpy;
			dstcpy++;
			srccpy++;
			n--;
		}
		return (dst);
	}
	return (NULL);
}

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	unsigned char	*dstcpy;
// 	unsigned char	*srccpy;

// 	if (!dst && !src)
// 		return (NULL);
// 	dstcpy = (unsigned char *)dst;
// 	srccpy = (unsigned char *)src;
// 	while (n)
// 	{
// 		*dstcpy = *srccpy;
// 		dstcpy++;
// 		srccpy++;
// 		n--;
// 	}
// 	return (dst);
// }
// #include <stdio.h>
// int main(void)
// {
// 	char dst[] = "helloworld";
// 	const char src[] = "good";
// 	ft_memcpy(dst+2, src, 2);
// 	printf("%s\n", dst);
// 	return (0);
// }