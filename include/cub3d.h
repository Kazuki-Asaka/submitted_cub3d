/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:45:21 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/30 17:26:42 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <libc.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <time.h>
# include "../libft/libft.h"

# define KEY_ESC		65307

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define DISPLAY_X		1000
# define DISPLAY_Y		600
# define DISPLAY_HALF	300

# define SPACE	10

# define NORTH			270
# define SOUTH			90
# define WEST			180
# define EAST			0

# define NORTH_IMG		0
# define SOUTH_IMG		1
# define WEST_IMG		2
# define EAST_IMG		3

# define VIEW_ANGLE		60
# define VIEW_ANGLE_Y	40
# define STEP			0.1

# define ANGLE			1

# define ESC			53
# define UP_ARROW		126
# define DOWN_ARROW		125
# define RIGHT_ARROW	124
# define LEFT_ARROW		123

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_data
{
	char	**map;
	int		display[DISPLAY_Y][DISPLAY_X];
	double	direction;
	double	pos_x;
	double	pos_y;
	int		max_x;
	int		max_y;
	int		xpm_width;
	int		xpm_height;
	void	*direction_img[4];
	bool	path[4];
	int		map_start_line;
	int		floor_rgb;
	int		ceiling_rgb;
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_status
{
	double	init_x;
	double	init_y;
	double	distance;
	int		dir;
	double	pos;
	double	angle;
	double	height_ratio;
	int		height;
	float	height_per_pixel;
}	t_status;

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_minimap
{
	t_coor	pos;
	t_coor	start;
	t_coor	end;
}	t_minimap;

// change_dir.c
void		turn_left(t_data *data);
void		turn_right(t_data *data);

// check_elements.c
void		check_elements(int fd, t_data *data);

// check_file.c
void		check_file(char *filename, t_data *data);

// check_map.c
void		check_map(t_data *data);

// create_map.c
void		create_map(char *filename, t_data *data);

// culc_distance.c
void		culc_distance(t_data *data);

// destroy.c
int			ft_destroy(t_data *data);

// draw_minimap.c
void		update_minimap(t_data *data);

// draw.c
void		reset_display(t_data *data);
void		update_display(t_data *data, int index, t_status status);
int			draw_map(t_data *data);

// error.c
void		print_error(char *msg);

// gnl
char		*get_next_line(int fd);
char		*gnl_strjoin(char *line, char *buf);
char		*ft_free(char **str);

// next_frame.c
int			next_frame(int keycode, t_data *data);

// check_distance.c
char		check_map_x_axis(t_data *data, double x, double y, double angle);
char		check_map_y_axis(t_data *data, double x, double y, double angle);
int			init_check(t_status data_init, t_data *data);

//set_culc_data.c
double		set_delta_x(double angle);
double		set_delta_y(double angle);
t_status	set_init_data_x_axis(t_data *data, double angle);
t_status	set_init_data_y_axis(t_data *data, double angle);
double		set_culc_distance(t_status data_init, t_data *data, double angle);

//choice_distance.c
t_status	choice_distance(t_data *data, double angle);

//angle_multiple_ninety.c
t_status	multiple_parallel_intersection(t_data *data, double angle);
t_status	multiple_vertical_intersection(t_data *data, double angle);

#endif