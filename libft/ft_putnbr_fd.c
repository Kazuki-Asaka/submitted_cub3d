/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:16:39 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 11:52:09 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	long	quotient;
	long	mod;
	char	c;

	num = (long)n;
	if (n < 0)
	{
		num *= -1;
		write(fd, "-", 1);
	}
	quotient = num / 10;
	mod = num % 10;
	if (quotient != 0)
		ft_putnbr_fd((int)quotient, fd);
	c = mod + '0';
	write(fd, &c, sizeof(char));
}

// int	main(void)
// {
// 	int	n =3002;

// 	ft_putnbr_fd(n, 1);
// 	return (0);
// }