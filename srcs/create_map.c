/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:38:58 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/30 14:46:58 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_map(t_data *data)
{
	int	j;

	j = 0;
	data->map = (char **)malloc(sizeof(char *) * (data->max_y + 1));
	if (!data->map)
		print_error("bad_alloc");
	while (j < data->max_y)
	{
		data->map[j] = (char *)malloc(sizeof(char) * (data->max_x + 1));
		if (!data->map[j])
			print_error("bad_alloc");
		data->map[j] = ft_memset(data->map[j], ' ', (size_t)data->max_x);
		data->map[j][data->max_x] = '\0';
		j++;
	}
	data->map[j] = NULL;
}

static void	skip_elements(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < data->map_start_line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
}

static void	check_direction(t_data *data, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (data->direction != -1)
			print_error("duplicate player position");
		data->pos_x = x + 0.5;
		data->pos_y = y + 0.5;
		if (c == 'N')
			data->direction = NORTH;
		else if (c == 'S')
			data->direction = SOUTH;
		else if (c == 'E')
			data->direction = EAST;
		else if (c == 'W')
			data->direction = WEST;
	}
}

static void	get_map(int fd, t_data *data)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (j < data->max_y)
	{
		line = get_next_line(fd);
		if (!line)
			print_error("no map");
		i = 0;
		while (line[i] != '\n' && line[i] != '\0')
		{
			check_direction(data, line[i], i, j);
			data->map[j][i] = line[i];
			i++;
		}
		free(line);
		j++;
	}
}

void	create_map(char *filename, t_data *data)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	init_map(data);
	skip_elements(data, fd);
	get_map(fd, data);
	if (data->pos_x == 0 && data->pos_y == 0)
		print_error("no player position");
	close (fd);
}
