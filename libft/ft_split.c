/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:55:41 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/29 19:02:46 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**split_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	*ft_strncpy(char const *s, int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**split_to_array(char const *s, char c, char **array)
{
	int	i;
	int	x;
	int	start;

	i = 0;
	x = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[x] = ft_strncpy(s, start, (size_t)(i - start));
			if (!array[x])
				return (split_free(array));
			x++;
		}
	}
	array[x] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**array;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	return (split_to_array(s, c, array));
}

// #include <stdio.h>
// int main(void)
// {
// 	char const str[] = "hikaru morisaki   ";
// 	char charset = ' ';
// 	char **tmp = ft_split(str, charset);

// 	int i = 0;
// 	while (tmp[i] != NULL)
// 	{
// 		printf("%s\n", tmp[i]);
// 		i++;
// 	}

// 	// char **tab;
// 	// tab = ft_split("", ' ');
// 	// printf("%s\n", *tab);
// 	return (0);
// }