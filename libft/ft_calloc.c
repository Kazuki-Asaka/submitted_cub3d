/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:14:02 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/02 12:43:14 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// どっちかが0のとき
// size_tの最大値の話

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == 0 || size == 0)
	{
		tmp = (void *)malloc(1);
		if (!tmp)
			return (NULL);
		ft_bzero(tmp, 1);
		return (tmp);
	}
	if (SIZE_MAX / count < size)
		return (NULL);
	tmp = (void *)malloc(sizeof(void) * size * count);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, size * count);
	return (tmp);
}
