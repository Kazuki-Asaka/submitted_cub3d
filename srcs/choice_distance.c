/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:09:27 by akazuki           #+#    #+#             */
/*   Updated: 2023/09/30 17:05:14 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_status	culc_intersection_x_axis(t_data *data, double angle)
{
	t_status	data_init;
	double		delta_y;

	delta_y = set_delta_y(angle);
	data_init.angle = angle;
	data_init = set_init_data_x_axis(data, angle);
	if (init_check(data_init, data) == 1)
	{
		data_init.distance = -1;
		return (data_init);
	}
	while (check_map_x_axis(data, data_init.init_x,
			data_init.init_y, angle) != '1')
	{
		data_init.init_x = data_init.init_x + delta_y;
		if (init_check(data_init, data) == 1)
			break ;
		if (((double)0 < angle && angle < (double)90)
			|| ((double)90 < angle && angle < (double)180))
			data_init.init_y++;
		else
			data_init.init_y--;
	}
	data_init.distance = set_culc_distance(data_init, data, angle);
	return (data_init);
}

t_status	culc_intersection_y_axis(t_data *data, double angle)
{
	t_status	data_init;
	double		delta_x;

	delta_x = set_delta_x(angle);
	data_init.angle = angle;
	data_init = set_init_data_y_axis(data, angle);
	if (init_check(data_init, data) == 1)
	{
		data_init.distance = -1;
		return (data_init);
	}
	while (check_map_y_axis(data, data_init.init_x, \
			data_init.init_y, angle) != '1')
	{
		data_init.init_y = data_init.init_y + delta_x;
		if (init_check(data_init, data) == 1)
			break ;
		if (((double)0 < angle && angle < (double)90)
			|| ((double)270 < angle && angle < (double)360))
			data_init.init_x++;
		else
			data_init.init_x--;
	}
	data_init.distance = set_culc_distance(data_init, data, angle);
	return (data_init);
}

t_status	choice_distance(t_data *data, double angle)
{
	t_status	x_axis;
	t_status	y_axis;

	x_axis = culc_intersection_x_axis(data, angle);
	y_axis = culc_intersection_y_axis(data, angle);
	if (x_axis.distance == (double)-1 || ((y_axis.distance != (double)-1) \
		&& x_axis.distance > y_axis.distance))
	{
		y_axis.dir = WEST_IMG;
		if (90 < angle && angle < 270)
			y_axis.dir = EAST_IMG;
		y_axis.pos = y_axis.init_y - (int)y_axis.init_y;
		return (y_axis);
	}
	else
	{
		x_axis.dir = SOUTH_IMG;
		if (angle < 180)
			x_axis.dir = NORTH_IMG;
		x_axis.pos = x_axis.init_x - (int)x_axis.init_x;
		return (x_axis);
	}
}
