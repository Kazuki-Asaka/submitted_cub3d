/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:17:33 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/09 20:30:03 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sがヌルのとき
// sよりstartが長いときの処理

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*substring;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < (size_t)start)
		return (ft_strdup(""));
	if (len > slen)
		len = slen;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
