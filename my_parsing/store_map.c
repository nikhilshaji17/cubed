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

int	copy_map(t_map *map, int start)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	map->map = ft_calloc(map->rows + 1, sizeof(char *));
	if (!map->map)
		return (print_error("Error: Malloc\n"));
	while (map->cmap[i] && j < map->rows)
	{
		map->map[j] = ft_strtrim(map->cmap[i], "\n\r");  //for windows \r
		if (!map->map[j])
		{
			while (j >= 0)
			{
				free_str(&map->map[j]);
				j--;
			}
			return (print_error("Error: Malloc\n"));
		}
		i++;
		j++;
	}
	map->map[j] = NULL;
	return (0);
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
				return (print_error("Error: Empty line(s) in map\n"));
			else
				map->rows++;
		}
		i++;
	}
	if (map->rows == 0)
		return (print_error("Error: Empty map\n"));
	return (copy_map(map, start));
}

int	check_map_space(t_map *map, int i, int j)
{
	if ((j + 1 < (int)(ft_strlen(map->map[i])) && map->map[i][j + 1]
	&& map->map[i][j + 1] != '1' && map->map[i][j + 1] != ' ')
	|| (j > 0 && map->map[i][j - 1] && map->map[i][j - 1] != '1'
	&& map->map[i][j - 1] != ' ') ||
	(i + 1 < (map->rows) && j < (int)ft_strlen(map->map[i + 1])
	&& map->map[i + 1] && map->map[i + 1][j] != '1'
	&& map->map[i + 1][j] != ' ') ||
	(i > 0 && j < (int)ft_strlen(map->map[i - 1]) && map->map[i - 1] &&
	map->map[i - 1][j] != '1' && map->map[i - 1][j] != ' '))
		return (0);
	return (1);
}

int	validate_spaces(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (map->map[i])
	{
		j = 1;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
			{
				if (!check_map_space(map, i, j))
					return (print_error("Error: Space is not closed\n"));
			}
			j++;
		}
		i++;
	}
	return (0);
}
