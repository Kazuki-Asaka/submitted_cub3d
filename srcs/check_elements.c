/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:39:00 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/29 23:02:24 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_path(char *line, int index, t_data *data)
{
	if (data->path[index] == true)
		print_error("element is duplicated");
	data->path[index] = true;
	if (ft_strchr(line, '\n'))
		line[ft_strchr(line, '\n') - line] = '\0';
	data->direction_img[index] = mlx_xpm_file_to_image(data->mlx,
			line, &(data->xpm_width), &(data->xpm_height));
	if (!data->direction_img[index])
		print_error("cannot open xpm file");
}

static void	check_rgb(char *line, int *color, int i)
{
	int	rgb;

	rgb = 0;
	if (line[0] < '0' || line[0] > '9')
		print_error("rgb is missing");
	rgb = ft_atoi(line);
	if (rgb < 0 || rgb > 255)
		print_error("rgb out of range");
	if (i == 0)
		*color += rgb * 256 * 256;
	else if (i == 1)
		*color += rgb * 256;
	else
		*color += rgb;
}

static void	check_color(char *line, int identifier, t_data *data)
{
	int	i;
	int	color;

	i = 0;
	color = 0;
	check_rgb(&line[i], &color, 0);
	i += ft_strchr(&line[i], ',') - &line[i] + 1;
	check_rgb(&line[i], &color, 1);
	i += ft_strchr(&line[i], ',') - &line[i] + 1;
	check_rgb(&line[i], &color, 2);
	if (identifier == 'F' && data->floor_rgb == -1)
		data->floor_rgb = color;
	else if (identifier == 'C' && data->ceiling_rgb == -1)
		data->ceiling_rgb = color;
	else
		print_error("element is duplicated");
}

static void	check_path_or_color(char *line, t_data *data, int *i)
{
	char	**elements;

	(*i)++;
	elements = ft_split(line, ' ');
	if (!elements || !elements[0] || !elements[1])
		print_error("element is missing");
	if (!ft_strcmp(elements[0], "NO"))
		check_path(elements[1], 0, data);
	else if (!ft_strcmp(elements[0], "SO"))
		check_path(elements[1], 1, data);
	else if (!ft_strcmp(elements[0], "WE"))
		check_path(elements[1], 2, data);
	else if (!ft_strcmp(elements[0], "EA"))
		check_path(elements[1], 3, data);
	else if (!ft_strcmp(elements[0], "F"))
		check_color(elements[1], 'F', data);
	else if (!ft_strcmp(elements[0], "C"))
		check_color(elements[1], 'C', data);
	else
		print_error("element is incorrect");
	split_free(elements);
}

void	check_elements(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			print_error("element is missing");
		if (line[0] != '\n')
			check_path_or_color(line, data, &i);
		data->map_start_line++;
		free(line);
	}
	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		data->map_start_line++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	data->max_y++;
}
