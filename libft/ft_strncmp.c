/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:42:08 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/02 16:35:05 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n-- && (*c1 != '\0' || *c2 != '\0'))
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char *str = "libft-test-tokyo";
// 	char *cmp = "libft-test-tokyo";
// 	int	len = strlen(str);
// 	char *cmp2 = calloc(10, 1);
// 	strlcpy(cmp2, "libft", 10);
// 	cmp2[5] = -42;
// 	// printf("%d\n", str[5]);
// 	// printf("%d\n", cmp2[5]);
// 	printf("%d\n", strncmp(str, cmp2, len));

// 	return (0);
// }