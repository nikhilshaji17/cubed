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

// my_parsing/elements.c
int		store_elem(t_elements *elem, char *line);
int		handle_tex(t_elements *elem, char *trim, char **arr);
int		assign_tex(char **tex, char *trim);

// init.c
void	init_data(t_data *data);
void	init_vars(t_vars *vars);

// free.c
void	fr_array(char **arr);
void	free_data(t_data *data);

#endif
