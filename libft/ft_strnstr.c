/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:14:55 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/16 17:36:24 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_same(const char *hay, const char *needle, char *tmp, size_t len)
{
	int	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (tmp[i] != needle[i] || (tmp + i - hay) >= (unsigned int)len)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp1;

	if (!needle)
		ft_strlen(needle);
	if (!len && !haystack)
		return (NULL);
	if (!haystack)
		ft_strlen(haystack);
	tmp1 = (char *)haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*tmp1 != '\0' && (tmp1 - haystack) < (unsigned int)len)
	{
		if (is_same(haystack, needle, tmp1, len) == 1)
			return (tmp1);
		else
			tmp1++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	char * empty = (char*)"";

// 	printf("%s\n", (strnstr("", "", 0)));
// 	printf("%s\n", (ft_strnstr("", "", 0)));
// 	return (0);
// }