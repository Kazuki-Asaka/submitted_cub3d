/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:31:42 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/11 17:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*rtn;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	rtn = tmp;
	while (*s1 != '\0')
	{
		*tmp = *s1;
		tmp++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*tmp = *s2;
		tmp++;
		s2++;
	}
	*tmp = '\0';
	return (rtn);
}
