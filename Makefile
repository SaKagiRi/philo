NAME		= philo
CC			= cc
CFLAGS		= -g3#-Wall -Wextra -Werror -g3

OBJ_DIR		= $(BUILD_DIR)/obj
BUILD_DIR	= build
LIBFT_DIR	= ./lib/KML
MLX_DIR		= ./lib/MLX42

HEADER		= -I ./include

FILE_MALLOC	= ft_calloc.c ft_linked_list.c ft_malloc.c
FT_MALLOC	= $(addprefix ft_malloc/, $(FILE_MALLOC))

FILE_M		= get_t.c philo.c clear.c atol.c time.c $(FT_MALLOC)
PATH_M		= src/main/
MAIN		= $(addprefix $(PATH_M), $(FILE_M))

FILE_S1		= parser.c init.c
PATH_S1		= src/stage_1/
STAGE_1		= $(addprefix $(PATH_S1), $(FILE_S1))

SRC			= $(MAIN) $(STAGE_1)

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) $(HEADER) -o $@
		@printf "\033[38;5;46m\033[1m⟪ Complete ⟫\033[0m\n"

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
