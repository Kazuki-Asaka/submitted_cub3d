/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:06:39 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/19 15:19:39 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	tmp1 = (const unsigned char *)s1;
	tmp2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	int	len = 30;
// 	char *str = calloc(30, sizeof(char));
// 	char *cmp = calloc(30, sizeof(char));
// 	memcpy(str, "libft-test-tokyo", 16);
// 	memcpy(cmp, "libft-test-tokyo", 16);
// 	memcpy(str + 20, "acdfg", 5);
// 	memcpy(cmp + 20, "acdfg", 5);

// 	int	i = 12;
// 	cmp = strndup(str, i);
// 	printf("%d\n", memcmp(str, cmp, i));
// 	return (0);
// }