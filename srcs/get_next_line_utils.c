/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:36:53 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/27 20:29:35 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	gnl_strlcat(char *line, char *buf, char *tmp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		tmp[i] = line[i];
		i++;
	}
	while (buf[j] != '\0')
	{
		tmp[i] = buf[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
}

char	*ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (NULL);
}

char	*gnl_strjoin(char *line, char *buf)
{
	char	*tmp;
	size_t	len;

	if (!line || !buf)
		return (NULL);
	len = ft_strlen(line) + ft_strlen(buf);
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	gnl_strlcat(line, buf, tmp);
	ft_free(&line);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	gnl_strlcat(tmp, "", line);
	ft_free(&tmp);
	return (line);
}
