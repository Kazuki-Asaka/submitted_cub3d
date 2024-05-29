/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:44:10 by hmorisak          #+#    #+#             */
/*   Updated: 2022/10/29 14:44:10 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char str[] = "0123456789";
// 	ft_bzero(str, 2);
// 	printf("%s\n",str);

// 	return 0;
// }