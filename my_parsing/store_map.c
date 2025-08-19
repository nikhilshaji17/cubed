/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:29:47 by nkunnath          #+#    #+#             */
/*   Updated: 2025/08/19 17:43:13 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	empty_line(char *str)
{
	if (*str == '\n')
		str++;
	return (*str == '\0');
}

int	store_map(t_map *map, int start)
{
	int	i;
	int	map_end;

	i = start;
	map_end = 0;
	map->rows = 0;
	while (map->cmap[i])
	{
		if (empty_line(map->cmap[i]))
			map_end = 1;
		else
		{
			if (map_end)
			{
				if (only_spaces(map->cmap[i]))
					return (print_error("Error: Empty line in map\n"));
			}
			else
				map->rows++;
		}
		i++;
	}
	if (map->rows == 0)
		return (print_error("Error: Empty map\n"));
	return (copy_map(map, start));
}
