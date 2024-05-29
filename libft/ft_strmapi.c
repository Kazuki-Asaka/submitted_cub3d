/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:47 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/16 17:50:35 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	slen;
	size_t	i;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	tmp = (char *)malloc(sizeof(char) * (slen + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		tmp[i] = f((unsigned int)i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
