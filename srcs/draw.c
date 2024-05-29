/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:17:00 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/30 17:27:09 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	reset_display(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < DISPLAY_Y / 2)
	{
		x = 0;
		while (x < DISPLAY_X)
		{
			data->display[y][x] = data->ceiling_rgb;
			x++;
		}
		y++;
	}
	while (y < DISPLAY_Y)
	{
		x = 0;
		while (x < DISPLAY_X)
		{
			data->display[y][x] = data->floor_rgb;
			x++;
		}
		y++;
	}
}

void	update_display(t_data *data, int index, t_status status)
{
	int		j;
	t_coor	cor;
	int		pos;
	char	*mlx_data_addr;
	int		current_pixel;

	cor.x = (int)(status.pos * data->xpm_width);
	cor.y = 0;
	current_pixel = 0;
	j = DISPLAY_HALF - status.height;
	while (j < DISPLAY_HALF + status.height)
	{
		pos = (cor.y * data->line_length + cor.x * (data->bits_per_pixel / 8));
		mlx_data_addr = mlx_get_data_addr(data->direction_img[status.dir],
				&data->bits_per_pixel, &data->line_length, &data->endian);
		if (0 <= j && j < DISPLAY_Y)
			data->display[j][index] = *(unsigned int *)(mlx_data_addr + pos);
		j++;
		while (((j - DISPLAY_HALF + status.height) / status.height_per_pixel)
			> current_pixel + 1 && cor.y < data->xpm_height)
		{
			current_pixel++;
			cor.y++;
		}
	}
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	while (y < DISPLAY_Y)
	{
		x = 0;
		while (x < DISPLAY_X)
		{
			my_mlx_pixel_put(data, x, y, data->display[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
