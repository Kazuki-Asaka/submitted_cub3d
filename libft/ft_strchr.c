/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:08:26 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/07 18:57:42 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char s[] = "tripouille";

// 	printf("%s\n", strchr(s, 't'));
// 	printf("%s\n", ft_strchr(s, 't'));
// 	printf("%s\n", strchr(s, 'l'));
// 	printf("%s\n", ft_strchr(s, 'l'));
// 	printf("%s\n", strchr(s, 'z'));
// 	printf("%s\n", ft_strchr(s, 'z'));
// 	printf("%s\n", strchr(s, 0));
// 	printf("%s\n", ft_strchr(s, 0));
// 	printf("%s\n", strchr(s, 't' + 256));
// 	printf("%s\n", ft_strchr(s, 't' + 256));

// 	return (0);
// }