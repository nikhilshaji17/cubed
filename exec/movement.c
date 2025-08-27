/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:23:36 by mnazar            #+#    #+#             */
/*   Updated: 2025/08/16 17:23:36 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	colour_floor_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(&data->image, x, y, data->elements.ceiling);
			else
				my_mlx_pixel_put(&data->image, x, y, data->elements.floor);
			x++;
		}
		y++;
	}
}

void	move_vertically(t_data *data, int direction)
{
	t_cord	vars;
	double	move_x;
	double	move_y;

	ft_bzero(&vars, sizeof(t_cord));
	if (direction == MUP)
	{
		move_x = data->player.dir_x * (MOV_SPEED * data->delta_time);
		move_y = data->player.dir_y * (MOV_SPEED * data->delta_time);
	}
	else
	{
		move_x = -data->player.dir_x * (MOV_SPEED * data->delta_time);
		move_y = -data->player.dir_y * (MOV_SPEED * data->delta_time);
	}
	move_player(data, move_x, move_y, vars);
}

void	move_horizontally(t_data *data, int direction)
{
	t_cord	vars;
	double	move_x;
	double	move_y;

	ft_bzero(&vars, sizeof(t_cord));
	if (direction == MRIGHT)
	{
		move_x = data->player.plane_x * (MOV_SPEED * data->delta_time);
		move_y = data->player.plane_y * (MOV_SPEED * data->delta_time);
	}
	else
	{
		move_x = -data->player.plane_x * (MOV_SPEED * data->delta_time);
		move_y = -data->player.plane_y * (MOV_SPEED * data->delta_time);
	}
	move_player(data, move_x, move_y, vars);
}

void	rotate(t_player *pl, int direction, t_data *data)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;
	double	cos_rot;
	double	sin_rot;

	if (direction == R_ROTATE)
		rot = ROT_SPEED * data->delta_time;
	else
		rot = -ROT_SPEED * data->delta_time;
	if (fabs(rot) > 0.1)
	{
		if (rot > 0)
			rot = 0.1;
		else
			rot = -0.1;
	}
	cos_rot = cos(rot);
	sin_rot = sin(rot);
	old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos_rot - pl->dir_y * sin_rot;
	pl->dir_y = old_dir_x * sin_rot + pl->dir_y * cos_rot;
	old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos_rot - pl->plane_y * sin_rot;
	pl->plane_y = old_plane_x * sin_rot + pl->plane_y * cos_rot;
}

void	check_movement(t_data *data)
{
	if (data->keys[0])
		move_vertically(data, MUP);
	if (data->keys[1])
		move_vertically(data, MDOWN);
	if (data->keys[2])
		move_horizontally(data, MLEFT);
	if (data->keys[3])
		move_horizontally(data, MRIGHT);
	if (data->keys[4])
		rotate(&data->player, L_ROTATE, data);
	if (data->keys[5])
		rotate(&data->player, R_ROTATE, data);
}
