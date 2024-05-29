/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:45:54 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/16 17:51:27 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*search_start(char const *s1, char const *set)
{
	char	*tmp;
	char	*set_cpy;

	tmp = (char *)s1;
	set_cpy = (char *)set;
	while (*s1 != '\0')
	{
		while (*set != '\0')
		{
			if (*s1 == *set)
			{
				tmp = (char *)(s1 + 1);
				break ;
			}
			set++;
		}
		if (*s1 != *set)
			return (tmp);
		s1++;
		set = set_cpy;
	}
	return (tmp);
}

static char	*search_end(char const *s1, char const *set, char *start)
{
	char	*tmp;
	char	*set_cpy;

	tmp = (char *)s1;
	set_cpy = (char *)set;
	while (s1 != start)
	{
		while (*set != '\0')
		{
			if (*s1 == *set)
			{
				tmp = (char *)(s1 - 1);
				break ;
			}
			set++;
		}
		if (*s1 != *set)
			return (tmp);
		s1--;
		set = set_cpy;
	}
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*rtn;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = search_start(s1, set);
	end = search_end(s1 + ft_strlen(s1) - 1, set, start);
	len = (size_t)(end - start + 1);
	if (*start == '\0')
		return (ft_strdup(""));
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	rtn = ft_memcpy(rtn, start, len);
	rtn[len] = '\0';
	return (rtn);
}
