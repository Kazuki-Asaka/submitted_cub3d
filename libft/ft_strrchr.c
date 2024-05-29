/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:15:00 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/18 11:27:31 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = NULL;
	while (1)
	{
		if (*s == (char)c)
			tmp = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (tmp);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	const char s[] = "helloworld";
// 	int c = 'a';

// 	printf("%s\n", strrchr(s, c));
// 	printf("%s\n", ft_strrchr(s, c));

// 	return (0);
// }