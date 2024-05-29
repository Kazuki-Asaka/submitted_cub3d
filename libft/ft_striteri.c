/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:45:57 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/09 20:17:36 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			slen;
	unsigned int	i;

	if (s && f)
	{
		slen = ft_strlen(s);
		i = 0;
		while ((size_t)i < slen)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
