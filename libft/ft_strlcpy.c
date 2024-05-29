/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:20:13 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/02 12:42:03 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	if (dstsize > 0)
	{
		while (dstsize-- != 1 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (len);
}
