/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:36:12 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/28 11:46:18 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_pixel(t_data *data, int i, int j, int color)
{
	int	start_x;
	int	max_x;
	int	max_y;

	start_x = i;
	max_x = i + SPACE;
	max_y = j + SPACE;
	while (j < max_y)
	{
		i = start_x;
		while (i < max_x)
		{
			data->display[j][i] = color;
			i++;
		}
		j++;
	}
}

static void	draw_minimap(t_data *data, t_coor start, t_coor end)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = start.x;
	while (start.y < end.y)
	{
		i = 0;
		x = start.x;
		while (x < end.x)
		{
			if (data->map[start.y][x] == '1')
				draw_pixel(data, i * SPACE + 20, j * SPACE + 20, 0xE7E7E7);
			else
				draw_pixel(data, i * SPACE + 20, j * SPACE + 20, 0x000080);
			if (x == (int)data->pos_x && start.y == (int)data->pos_y)
				draw_pixel(data, i * SPACE + 20, j * SPACE + 20, 0x00FF0000);
			i++;
			x++;
		}
		j++;
		start.y++;
	}
}

static t_minimap	init_minimap(t_data *data, int x, int y)
{
	t_minimap	minimap;

	minimap.pos.x = (int)data->pos_x;
	minimap.pos.y = (int)data->pos_y;
	minimap.start.x = minimap.pos.x - x;
	minimap.start.y = minimap.pos.y - y;
	minimap.end.x = minimap.pos.x + x;
	minimap.end.y = minimap.pos.y + y;
	return (minimap);
}

static void	draw_part_of_minimap(t_data *data, int center_x, int center_y)
{
	t_minimap	minimap;

	minimap = init_minimap(data, center_x, center_y);
	if (minimap.pos.x < center_x)
	{
		minimap.start.x = 0;
		minimap.end.x = center_x * 2;
	}
	if (minimap.pos.x > data->max_x - center_x)
	{
		minimap.start.x = data->max_x - center_x * 2;
		minimap.end.x = data->max_x;
	}
	if (minimap.pos.y < center_y)
	{
		minimap.start.y = 0;
		minimap.end.y = center_y * 2;
	}
	if (minimap.pos.y > data->max_y - center_y)
	{
		minimap.start.y = data->max_y - center_y * 2;
		minimap.end.y = data->max_y;
	}
	draw_minimap(data, minimap.start, minimap.end);
}

void	update_minimap(t_data *data)
{
	t_coor	start;
	t_coor	end;

	if (data->max_x * SPACE > DISPLAY_X / 10
		|| data->max_y * SPACE > DISPLAY_Y / 5)
		draw_part_of_minimap(data, DISPLAY_X / 200, DISPLAY_Y / 100);
	else
	{
		start.x = 0;
		start.y = 0;
		end.x = data->max_x;
		end.y = data->max_y;
		draw_minimap(data, start, end);
	}
}
