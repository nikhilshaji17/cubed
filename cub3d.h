#ifndef CUB3D_H
# define CUB3D_H

// # include "libft/libft.h"
// # include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
#  include "minilibx_mac/mlx.h"
// #  include "minilibx-linux/mlx.h" //for windows/linux

# if __APPLE__
#  define ESC_KEY 53
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define RIGHT_ARROW 124
#  define LEFT_ARROW 123
# elif __linux__
#  define ESC_KEY 65307
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define RIGHT_ARROW 65363
#  define LEFT_ARROW 65361
# endif
// # define WIN_WIDTH 800
// # define WIN_HEIGHT 600
// # define ESC_KEY 65307 // Linux (X11). For Mac use 53.

# define GREEN 0x228B22
# define SKYBLUE 0x87CEEB
# define RED 0xFF0000
# define DARKRED 0x800000

#define MOVE_SPEED 0.1
#define ROT_SPEED 0.05

typedef struct s_vars
{
	int				i;
	int				j;
	int				k;
}					t_vars;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void    *img;          // MLX image pointer
    char    *addr;         // pointer to image data (pixel array)
    int     bits_per_pixel;
    int     line_length;
    int     endian; 
	double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
}	t_game;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_image;

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
	int				floor;
	int				ceiling;
	int				all_parsed;
}					t_elements;

typedef struct s_player
{
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
}					t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_image			img;
}			t_mlx;

typedef struct s_textures
{
	t_image			no;
	t_image			so;
	t_image			we;
	t_image			ea;
}					t_textures;

typedef struct s_ray
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			wallx;
	int				line_height;
	int				tex_num;
}					t_ray;

typedef struct s_data
{
	t_elements		elements;
	t_mlx			mlx;
	t_map			map;
	t_player		player;
	t_image			image;
	t_ray			ray;
	t_textures		texture;
	double			delta_time;
	struct timeval	last;
	bool			keys[7];
}					t_data;

void draw_background(t_game *game);
void draw_walls(t_game *game);
int		close_game(t_game *game);

//main.c
void	init_start_game(t_data *data);

//init.c
void	init_data(t_data *data);
void	init_vars(t_vars *vars);
void	init_texture(t_data *data);
void	xpm_to_image(t_data *data);
void	init_player(t_data *data);

//free.c
void fr_array(char **arr);
void	free_data(t_data *data);
void	destroy_image(t_data *data);

//elements.c
int	handle_color(char **str);
int	parse_rgb(char *str);
int	handle_tex(t_elements *elem, char *trim, char **arr);
int	store_elem(t_elements *elem, char *line);

//file_utils.c
int	file_error(int id);
int	check_file(char *file);
int	get_file_size(char *file);
int	print_error(char *str);
int	read_file_array(char *file, t_map *map, t_vars var);

//map_utils.c
void	calculate_map_rows(t_map *map);
int	top_bot_row(char *line);
int	only_spaces(char *str);
int	check_multiple_commas(char *str);
void	free_str(char **str);

//parse_map.c
int	store_tex(t_elements *elem, char *trim, char **arr);
int	assign_tex(char **tex, char *trim);
int	parse_elements(t_elements *elem, t_map *map, t_vars *vars);
int	parse_map(char *argv, t_data *data);

//store_map.c
int	empty_line(char *str);
int	copy_map(t_map *map, int start);
int	store_map(t_map *map, int start);
int	check_map_space(t_map *map, int i, int j);
int	validate_spaces(t_map *map);

//validate_map.c
int	validate_map_chars(t_map *map, t_vars vars);
int	validate_map_walls(t_map *map, t_vars vars);
int	check_neighbours(t_map *map, int i, int j);
int	valid_zero_player(t_map *map);
int	validate_map(t_map *map);

//hooks.c
void    mlx_loops_hooks(t_data *data);
int	key_release(int keycode, t_data *data);
int	key_press(int keycode, t_data *data);
int	exit_window(t_data *data);

#endif
