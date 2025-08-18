#include "../cub3d.h"

int	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	close(fd);
	return (0);
}

int	get_file_size(char *file)
{
	int		fd;
	int		size;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

int	print_error(char *str)
{
	if (str)
	{
		write(2, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int	read_file_array(char *file, t_map *map, t_vars var, int size)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		map->cmap[var.i] = line;
		var.i++;
		line = get_next_line(fd);
	}
	map->cmap[var.i] = NULL;
	close(fd);
	if (var.i != size)
	{
		fr_array(map->cmap);
		return (1);
	}
	return (0);
}

int	parse_elements(t_elements *elem, t_map *map, t_vars *vars)
{
	while (map->cmap[vars->i] && elem->all_parsed < 6)
	{
		if (only_spaces(map->cmap[vars->i]))
		{
			if (store_elem(elem, map->cmap[vars->i]) == 0)
				elem->all_parsed++;
			else
				return (print_error("Error: Invalid/Missing element\n"));
		}
		vars->i++;
	}
	if (elem->all_parsed < 6)
		return (print_error("Error: Missing elements\n"));
	while (map->cmap[vars->i] && !only_spaces(map->cmap[vars->i]))
		vars->i++;
	if (store_map(map, vars->i))
		return (1);
	return (0);
}

int	parse_map(char *argv, t_data *data)
{
	t_map		*map;
	t_vars		vars;
	int			size;
	t_elements	*elements;

	init_vars(&vars);
	map = &data->map;
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
	if (parse_elements(elements, map, vars))
		return (1);
	return (0);
}