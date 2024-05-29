/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:10:25 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/28 11:40:57 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_map_elements(char *line, int line_len)
{
	int	i;

	i = 0;
	while (i < line_len)
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' '
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			i++;
		else
			print_error("map element is incorrect");
	}	
}

static void	get_map_info(int fd, t_data *data)
{
	char	*line;
	int		line_len;

	line_len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			line[ft_strchr(line, '\n') - line] = '\0';
		line_len = ft_strlen(line);
		if (ft_strlen(line) == 0)
			print_error("map is missing");
		if (line_len > data->max_x)
			data->max_x = line_len;
		check_map_elements(line, line_len);
		data->max_y++;
		free(line);
	}
}

void	check_file(char *filename, t_data *data)
{
	char	*dot;
	int		fd;

	dot = ft_strchr(filename, '.');
	if (!dot)
		print_error("filename incorrect");
	if (ft_strcmp(dot, ".cub"))
		print_error("filename incorrect");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("cannot open file");
	check_elements(fd, data);
	get_map_info(fd, data);
	close (fd);
}
