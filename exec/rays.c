/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:45:51 by mnazar            #+#    #+#             */
/*   Updated: 2025/08/17 17:45:51 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_ray_delta(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = (2 * x / (double)WIN_WIDTH) - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

static void	init_step_side(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

static void	dda_algo(t_ray *ray, t_data *data)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_y < 0 || ray->map_y >= data->map.rows
			|| ray->map_x >= (int)ft_strlen(data->map.map[ray->map_y]))
		{
			ray->hit = 1;
			break ;
		}
		if (data->map.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	check_ray_side(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	if (ray->side == 0)
	{
		ray->wallx = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
		if (ray->step_x < 0)
			ray->wallx = 1.0 - ray->wallx + floor(ray->wallx);
	}
	else
	{
		ray->wallx = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
		if (ray->step_y < 0)
			ray->wallx = 1.0 - ray->wallx + floor(ray->wallx);
	}
	ray->wallx -= floor(ray->wallx);
}

void	cast_rays(t_ray *ray, t_player *player, t_data *data)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_delta(ray, player, x);
		init_step_side(ray, player);
		dda_algo(ray, data);
		check_ray_side(ray, player);
		draw_walls(ray, data, x);
		x++;
	}
}
