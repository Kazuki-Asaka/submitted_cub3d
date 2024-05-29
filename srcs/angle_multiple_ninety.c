/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_multiple_ninety.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:03:21 by akazuki           #+#    #+#             */
/*   Updated: 2023/09/29 21:27:17 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_status	multiple_parallel_intersection(t_data *data, double angle)
{
	t_status	data_init;
	int			x_int;

	x_int = data->pos_x;
	data_init.angle = angle;
	data_init.init_y = data->pos_y;
	if (angle == (double) 0)
		x_int ++;
	data_init.init_x = (double)x_int;
	while (check_map_y_axis(data, data_init.init_x,
			data_init.init_y, angle) != '1')
	{
		if (angle == 0)
			data_init.init_x = data_init.init_x + (double)1;
		else
			data_init.init_x = data_init.init_x - (double)1;
	}
	if (angle == (double)0)
		data_init.distance = data_init.init_x - data->pos_x;
	else
		data_init.distance = data_init.init_x;
	return (data_init);
}

t_status	multiple_vertical_intersection(t_data *data, double angle)
{
	t_status	data_init;
	int			y_int;

	y_int = data->pos_y;
	data_init.angle = angle;
	data_init.init_x = data->pos_x;
	if (angle == (double) 90)
		y_int ++;
	data_init.init_y = (double)y_int;
	while (check_map_x_axis(data, data_init.init_x,
			data_init.init_y, angle) != '1')
	{
		if (angle == 90)
			data_init.init_y = data_init.init_y + (double)1;
		else
			data_init.init_y = data_init.init_y - (double)1;
	}
	if (angle == (double)270)
		data_init.distance = data->pos_y - data_init.init_y;
	else
		data_init.distance = data_init.init_y;
	return (data_init);
}
