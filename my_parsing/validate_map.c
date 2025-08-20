/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:17:03 by marvin            #+#    #+#             */
/*   Updated: 2025/08/20 14:17:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_map_chars(t_map *map, t_vars vars)
{
	init_vars(&vars);
	while (map->map[vars.i])
	{
		vars.j = 0;
		while (map->map[vars.i][vars.j])
		{
			if (ft_strchr("01NSEW ", map->map[vars.i][vars.j]) == NULL)
				return (print_error("Error: Invalid character in map\n"));
			if (ft_strchr("NSEW", map->map[vars.i][vars.j]))
			{
				if (vars.k)
					return (print_error("Error: Multiple players\n"));
				map->p_x = vars.j;
				map->p_y = vars.i;
				map->direction = map->map[vars.i][vars.j];
				vars.k++;
			}
			vars.j++;
		}
		vars.i++;
	}
	if (!vars.k)
		return (print_error("Error: No player\n"));
	return (0);
}

int	validate_map_walls(t_map *map, t_vars vars)
{
	int	i;

	i = 0;
	init_vars(&vars);
	if (top_bot_row(map->map[0]) == 0 || !top_bot_row(map->map[map->rows - 1]) == 0)
		return (print_error("Error: Border is not closed\n"));
	while (++i < map->rows - 1)
	{
		vars.k = ft_strlen(map->map[i]);
		vars.j = 0;
		while (map->map[i][vars.j] == ' ')
			vars.j++;
		if (map->map[i][vars.j] == '\0')
		{
			i++;
			continue ;
		}
		if (map->map[i][vars.j] != '1')
			return (print_error("Error: Right border is not closed\n"));
		vars.j = vars.k - 1;
		while (vars.j >= 0 && map->map[i][vars.j] == ' ')
			vars.j--;
		if (map->map[i][vars.j] != '1')
			return (print_error("Error: Left border is not closed\n"));
	}
	return (0);
}

int	validate_map(t_map *map)
{
	t_vars	vars;

	if (validate_map_chars(map, vars) == 1)
		return (1);
	// calculate_map_rows(map); // We calculated this earlier
	// if (validate_map_walls(map, vars) == 1)
	// 	return (1);
	// if (validate_spaces(map) == 1)
	// 	return (1);
	// if (valid_zero_player(map) == 1)
	// 	return (1);
	return (0);
}