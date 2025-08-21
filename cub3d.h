#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_map
{
	char			*fullcub;
	char			**cmap;
	char			**map;
	int				rows;
	int				cols;
	int				p_x;
	int				p_y;
	char			direction;
}					t_map;

typedef struct s_elements
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				floor_count;
	int				ceil_count;
	int				no_count;
	int				so_count;
	int				ea_count;
	int				we_count;
	int				floor;
	int				ceiling;
	int				all_parsed;
}					t_elements;

typedef struct s_vars
{
	int				i;
	int				j;
	int				k;
}					t_vars;

typedef struct s_data
{
	t_elements		elements;
	// t_mlx			mlx;
	t_map			map;
	// t_player		player;
	// t_image			image;
	// t_ray			ray;
	// t_textures		texture;
	double			delta_time;
	// struct timeval	last;
	bool			keys[7];
}					t_data;

// my_parsing/parse_map.c
int		parse_map(char *argv, t_data *data);
int		parse_elements(t_elements *elems, t_map *map, t_vars vars);
int		store_tex(t_elements *elem, char *trim, char **arr);

// my_parsing/file_utils.c
int		check_file(char *file);
int		read_file_array(char *file, t_map *map, t_vars vars, int size);
int		print_error(char *str);
int		get_file_size(char *file);

// my_parsing/map_utils.c
int		only_spaces(char *str);
int		check_multiple_commas(char *str);
void	free_str(char **str);
void	calculate_map_rows(t_map *map);
int		top_bot_row(char *line);

// my_parsing/map_utils_2.c
void	check_counts(char c, t_elements *elem);
int		check_map_space(t_map *map, int i, int j);
int		validate_spaces(t_map *map);

// my_parsing/elements.c
int		store_elem(t_elements *elem, char *line);
int		handle_tex(t_elements *elem, char *trim, char **arr);
int		assign_tex(char **tex, char *trim);
int		parse_rgb(char c, t_elements *elem, char *str);
int		handle_color(char **str);

// my_parsing/store_map.c
int		store_map(t_map *map, int start);
int		empty_line(char *str);
int		copy_map(t_map *map, int start);

// my_parsing/validate_map.c
int		validate_map(t_map *map);
int		validate_map_chars(t_map *map, t_vars vars);
int		validate_map_walls(t_map *map, t_vars vars);
int		valid_zero_player(t_map *map);
int		check_neighbours(t_map *map, int i, int j);

// my_parsing/validate_utils.c
int		check_eastside(t_map *map, int i, int j);
int		check_westside(t_map *map, int i, int j);
int		check_southside(t_map *map, int i, int j);
int		check_northside(t_map *map, int i, int j);

// init.c
void	init_data(t_data *data);
void	init_vars(t_vars *vars);

// free.c
void	fr_array(char **arr);
void	free_data(t_data *data);

#endif
