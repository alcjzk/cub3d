# Targets
NAME		= cub3D
LIBFT 		= libft/libft.a

# Directories
OBJ_DIR				= obj/
SRC_DIR				= $(sort $(dir $(wildcard src/*/))) src/
INC_DIR				= $(SRC_DIR) libft/inc/
LIB_DIR				= libft

# Flags setup
CC		= cc
OPT		= 0
LIB		= ft mlx
WARN	= all extra error
EXTRA	= -MP -MMD -g

# Compiler flags
override CFLAGS 	+= $(EXTRA) $(OPT:%=-O%) $(INC_DIR:%=-I%) $(WARN:%=-W%)
# Linker flags
override LDFLAGS	+= $(LIB_DIR:%=-L%) $(LIB:%=-l%)

# Sources
SRCS =				\
vector.c			\
vector_extend.c		\
vector_position.c	\
vector_remove.c		\
vector_reserve.c	\
validate.c			\
get_color.c			\
get_elements.c		\
get_map.c			\
check_walls.c		\
validate_map.c		\
main.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(OBJ_DIR)%.d)

.PHONY: all clean fclean re obj_dir $(LIBFT)

all: $(NAME)

$(LIBFT):
	make -C libft OBJ_DIR="../obj/"

$(NAME): $(OBJS) | $(LIBFT)
	@echo ""
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)%.o: %.c | obj_dir
	$(CC) $(CFLAGS) -c -o $@ $<

run: all
	./$(NAME)

obj_dir:
	@mkdir -p $(OBJ_DIR)

re: fclean all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

debug: fclean
	make -C libft OBJ_DIR="../obj/" FLAGS="-g -fsanitize=address"
	make $(NAME) CFLAGS="-g -fsanitize=address"

vpath %.c $(SRC_DIR)
-include $(DEPS)
