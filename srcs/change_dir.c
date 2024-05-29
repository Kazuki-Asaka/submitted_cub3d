/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:29:53 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/28 11:30:07 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_data *data)
{
	if (data->direction - ANGLE < 0)
		data->direction = data->direction + 360 - ANGLE;
	else
		data->direction -= ANGLE;
}

void	turn_right(t_data *data)
{
	if (data->direction + ANGLE >= 360)
		data->direction = data->direction - 360 + ANGLE;
	else
		data->direction += ANGLE;
}
