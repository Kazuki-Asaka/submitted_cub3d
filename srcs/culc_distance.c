/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   culc_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:34:56 by akazuki           #+#    #+#             */
/*   Updated: 2023/09/30 17:28:43 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_status	set_height(t_status result_data, t_data *data)
{
	result_data.height_ratio = atan(0.5 / result_data.distance) / \
	M_PI * 180 / (double)VIEW_ANGLE_Y * (double) 2;
	result_data.height = (int)DISPLAY_HALF * result_data.height_ratio;
	result_data.height_per_pixel = (double)result_data.height / \
	(double)(data->xpm_height / 2);
	return (result_data);
}

void	step_position(t_data *data, double angle, int x)
{
	t_status	result_data;

	if (angle == (double)0 || angle == (double)180)
	{
		result_data = multiple_parallel_intersection(data, angle);
		result_data.dir = EAST_IMG;
		if (angle == (double)0)
			result_data.dir = WEST_IMG;
		result_data.pos = result_data.init_y - (int)result_data.init_y;
	}
	else if (angle == (double)90 || angle == (double)270)
	{
		result_data = multiple_vertical_intersection(data, angle);
		result_data.dir = SOUTH_IMG;
		if (angle == ((double)90))
			result_data.dir = NORTH_IMG;
		result_data.pos = result_data.init_x - (int)result_data.init_x;
	}
	else
		result_data = choice_distance(data, angle);
	result_data = set_height(result_data, data);
	update_display(data, x, result_data);
}

void	culc_distance(t_data *data)
{
	double	shift_angle;
	double	start_angle;
	int		x;

	x = 0;
	shift_angle = (double)VIEW_ANGLE / (double)DISPLAY_X;
	start_angle = data->direction - (double)VIEW_ANGLE / (double)2;
	if (start_angle < (double)0)
		start_angle = start_angle + (double)360;
	while (x <= (int)DISPLAY_X)
	{
		if (start_angle >= (double)360)
			start_angle = start_angle - (double)360;
		else if (start_angle < (double)0)
			start_angle = start_angle + (double)360;
		step_position(data, start_angle, x);
		start_angle += shift_angle;
		x++;
	}
	update_minimap(data);
}
