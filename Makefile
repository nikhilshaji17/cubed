NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c init.c free.c \
	  my_parsing/file_utils.c my_parsing/parse_map.c my_parsing/map_utils.c my_parsing/elements.c \
	  get_next_line/get_next_line.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_strchr.c \
	  libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strtrim.c \
	  libft/ft_substr.c libft/ft_split.c libft/ft_atoi.c libft/ft_isdigit.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re