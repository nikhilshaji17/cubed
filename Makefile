NAME = cub3d
# CC = gcc
CC = cc
MLX_DIR = ./minilibx_mac
CFLAGS = -Wall -Wextra -Werror

SRC = main.c init.c free.c \
	  my_parsing/file_utils.c my_parsing/parse_map.c my_parsing/map_utils.c my_parsing/elements.c my_parsing/store_map.c \
	  my_parsing/validate_map.c my_parsing/map_utils_2.c my_parsing/validate_utils.c \
	  get_next_line/get_next_line.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_strchr.c \
	  libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strtrim.c \
	  libft/ft_substr.c libft/ft_split.c libft/ft_atoi.c libft/ft_isdigit.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


# @$(MAKE) -C $(MLX_DIR)
# $(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
# @$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re