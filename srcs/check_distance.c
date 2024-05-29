/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:57:32 by akazuki           #+#    #+#             */
/*   Updated: 2023/09/29 21:33:24 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	check_map_x_axis(t_data *data, double x, double y, double angle)
{
	int	x_int;
	int	y_int;

	x_int = (int)x;
	y_int = (int)y;
	if ((double)180 < angle && angle < (double)360)
		y_int--;
	return (data->map[y_int][x_int]);
}

char	check_map_y_axis(t_data *data, double x, double y, double angle)
{
	int	x_int;
	int	y_int;

	x_int = (int)x;
	y_int = (int)y;
	if ((double)90 < angle && angle < 270)
		x_int--;
	return (data->map[y_int][x_int]);
}

int	init_check(t_status data_init, t_data *data)
{
	if (((double)0 <= data_init.init_x \
		&& data_init.init_x <= (double)data->max_x)
		&& ((double)0 <= data_init.init_y \
		&& data_init.init_y <= (double)data->max_y))
		return (0);
	else
		return (1);
}
