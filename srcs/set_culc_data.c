/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_culc_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:00:35 by akazuki           #+#    #+#             */
/*   Updated: 2023/09/30 17:07:17 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	set_delta_x(double angle)
{
	double	delta_x;

	delta_x = tan (angle * M_PI / (double)180);
	if (((double)90 < angle && angle < (double)180)
		|| ((double)180 < angle && angle < (double)270))
		delta_x = -delta_x;
	return (delta_x);
}

double	set_delta_y(double angle)
{
	double	delta_y;

	delta_y = (double)1 / tan (angle * M_PI / 180);
	if (((double)180 < angle && angle < (double)270)
		|| ((double)270 < angle && angle < (double)360))
		delta_y = -delta_y;
	return (delta_y);
}

t_status	set_init_data_x_axis(t_data *data, double angle)
{
	int			dx;
	int			dy;
	t_status	data_init;
	double		tmp;

	dx = (int)data->pos_x;
	dy = (int)data->pos_y;
	if (((double)0 < angle && angle < (double)90)
		|| ((double)90 < angle && angle < (double)180))
		dy++;
	if (dy > data->pos_y)
		tmp = (double)dy - data->pos_y;
	else
		tmp = data->pos_y - (double)dy;
	if (((double)180 < angle && angle < (double)270)
		|| ((double)270 < angle && angle < (double)360))
		tmp = -tmp;
	data_init.init_y = (double)dy;
	data_init.init_x = data->pos_x + tmp / tan (angle * M_PI / 180);
	return (data_init);
}

t_status	set_init_data_y_axis(t_data *data, double angle)
{
	int			dx;
	int			dy;
	t_status	data_init;
	double		tmp;

	dx = (int)data->pos_x;
	dy = (int)data->pos_y;
	if (((double)0 < angle && angle < (double)90)
		|| ((double)270 < angle && angle < (double)360))
		dx++;
	if ((double)dx > data->pos_x)
		tmp = (double)dx - data->pos_x;
	else
		tmp = data->pos_x - (double)dx;
	if (((double)90 < angle && angle < (double)180)
		|| ((double)180 < angle && angle < (double)270))
		tmp = -tmp;
	data_init.init_x = (double)dx;
	data_init.init_y = data->pos_y + tmp * tan(angle * M_PI / 180);
	return (data_init);
}

double	set_culc_distance(t_status data_init, t_data *data, double angle)
{
	double	tmp_distance;
	double	delta_x;
	double	delta_y;

	delta_x = data_init.init_x - data->pos_x;
	delta_y = data_init.init_y - data->pos_y;
	tmp_distance = sqrt(pow(delta_x, 2.0) + pow(delta_y, 2.0));
	tmp_distance = tmp_distance * cos((data->direction - angle) * \
	M_PI / (double)180);
	return (tmp_distance);
}
