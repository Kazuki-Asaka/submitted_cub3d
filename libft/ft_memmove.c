/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:59:14 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/16 18:08:59 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;
	size_t			i;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (src >= dst)
	{
		while (i < len)
		{
			dstcpy[i] = srccpy[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dstcpy[len] = srccpy[len];
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char *src = malloc(100);
// 	for (int i = 0; i < 100; i++)
// 		src[i] = i;
// 	char *dst = malloc(100);
// 	char s1 = memmove(dst, dst + 21, 50);
// 	char s2 = ft_memmove(dst, dst + 21, 50);
// 	printf("%s\n", dst);

// 	return (0);
// }