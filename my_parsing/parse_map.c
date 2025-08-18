/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:14:44 by mnazar            #+#    #+#             */
/*   Updated: 2025/08/18 15:50:56 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	assign_tex(char **tex, char *trim)
{
	if (*tex)
		return (print_error("Error: Element already exists\n"));
	*tex = ft_strdup(trim);
	if (*tex)
		return (0);
	return (print_error("Error: Strdup failure\n"));
}

int	store_tex(t_elements *elem, char *trim, char **arr)
{
	if (ft_strncmp(arr[0], "NO", 3) == 0)
		return (assign_tex(&elem->no, trim));
	else if (ft_strncmp(arr[0], "SO", 3) == 0)
		return (assign_tex(&elem->so, trim));
	else if (ft_strncmp(arr[0], "WE", 3) == 0)
		return (assign_tex(&elem->we, trim));
	else if (ft_strncmp(arr[0], "EA", 3) == 0)
		return (assign_tex(&elem->ea, trim));
	return (1);
}

int	parse_elements(t_elements *elem, t_map *map, t_vars vars)
{
	while (map->cmap[vars.i] != NULL && elem->all_parsed < 6)
	{
		if (!only_spaces(map->cmap[vars.i]))
		{
			if (store_elem(elem, map->cmap[vars.i]) == 0)
				elem->all_parsed++;
			else
				return (print_error("Error: .cub file has invalid or missing elements\n"));
		}
		vars.i += 1;
	}
	return (0);
}

int	parse_map(char *argv, t_data *data)
{
	t_map		*map;
	t_vars		vars;
	int			size;
	t_elements	*elems;

	init_vars(&vars);
	map = &data->map;
	elems = &data->elements;
	if (check_file(argv))
		return (1);
	size = get_file_size(argv);
	if (size == 0)
		return (printf("File is empty\n"), 1);
	map->cmap = ft_calloc(size + 1, sizeof(char *));
	if (!map->cmap)
		return (print_error("Error: During Map Malloc\n"));
	if (read_file_array(argv, map, vars, size))
		return (print_error("Error: During CMap creation\n"));
	if (parse_elements(elems, map, vars))
		return (1);
	return (0);
}
