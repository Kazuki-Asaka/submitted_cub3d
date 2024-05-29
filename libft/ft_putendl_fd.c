/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:11:12 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/19 13:50:00 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	slen;
	size_t	i;

	if (s)
	{
		slen = ft_strlen(s);
		i = 0;
		while (i < slen)
		{
			write(fd, &s[i], sizeof(char));
			i++;
		}
		write(fd, "\n", 1);
	}
}
