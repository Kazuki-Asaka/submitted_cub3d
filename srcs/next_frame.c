/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:01:19 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/29 23:42:55 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	go_straight(t_data *data)
{
	double	step_x;
	double	step_y;

	step_x = (STEP + 0.2) * cos(data->direction * M_PI / 180) + data->pos_x;
	step_y = (STEP + 0.2) * sin(data->direction * M_PI / 180) + data->pos_y;
	if (data->map[(int)step_y][(int)step_x] != '1')
	{
		step_x = STEP * cos(data->direction * M_PI / 180);
		step_y = STEP * sin(data->direction * M_PI / 180);
		data->pos_x += step_x;
		data->pos_y += step_y;
	}
}

static void	go_back(t_data *data)
{
	double	step_x;
	double	step_y;
	double	direction;

	direction = data->direction + 180;
	step_x = (STEP + 0.2) * cos(direction * M_PI / 180) + data->pos_x;
	step_y = (STEP + 0.2) * sin(direction * M_PI / 180) + data->pos_y;
	if (data->map[(int)step_y][(int)step_x] != '1')
	{
		step_x = STEP * cos((data->direction + 180) * M_PI / 180);
		step_y = STEP * sin((data->direction + 180) * M_PI / 180);
		data->pos_x += step_x;
		data->pos_y += step_y;
	}
}

static void	go_left(t_data *data)
{
	double	step_x;
	double	step_y;
	double	direction;

	direction = data->direction - 90;
	step_x = (STEP + 0.2) * cos(direction * M_PI / 180) + data->pos_x;
	step_y = (STEP + 0.2) * sin(direction * M_PI / 180) + data->pos_y;
	if (data->map[(int)step_y][(int)step_x] != '1')
	{
		step_x = STEP * cos((data->direction - 90) * M_PI / 180);
		step_y = STEP * sin((data->direction - 90) * M_PI / 180);
		data->pos_x += step_x;
		data->pos_y += step_y;
	}
}

static void	go_right(t_data *data)
{
	double	step_x;
	double	step_y;
	double	direction;

	direction = data->direction + 90;
	step_x = (STEP + 0.2) * cos(direction * M_PI / 180) + data->pos_x;
	step_y = (STEP + 0.2) * sin(direction * M_PI / 180) + data->pos_y;
	if (data->map[(int)step_y][(int)step_x] != '1')
	{
		step_x = STEP * cos((data->direction + 90) * M_PI / 180);
		step_y = STEP * sin((data->direction + 90) * M_PI / 180);
		data->pos_x += step_x;
		data->pos_y += step_y;
	}
}

int	next_frame(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_destroy(data);
	if (keycode == KEY_W)
		go_straight(data);
	if (keycode == KEY_S)
		go_back(data);
	if (keycode == KEY_A)
		go_left(data);
	if (keycode == KEY_D)
		go_right(data);
	if (keycode == LEFT_ARROW)
		turn_left(data);
	if (keycode == RIGHT_ARROW)
		turn_right(data);
	reset_display(data);
	culc_distance(data);
	return (0);
}
