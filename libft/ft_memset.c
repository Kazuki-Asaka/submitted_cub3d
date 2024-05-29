/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:20:22 by hmorisak          #+#    #+#             */
/*   Updated: 2022/10/12 16:20:22 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)buf;
	while (n--)
	{
		*tmp = (unsigned char)ch;
		tmp++;
	}
	return (buf);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "0123456789";
// 	ft_memset(str+2, '*', 5);
// 	printf("%s\n",str);

// 	return 0;
// }