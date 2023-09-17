# Targets
NAME		= cub3D
LIBFT 		= libft/libft.a
MLX42		= MLX42/build/libmlx42.a

# Directories
BREW_PATH			= $(shell brew --prefix)
OBJ_DIR				= obj/
SRC_DIR				= $(sort $(dir $(wildcard src/*/))) src/
INC_DIR				= $(SRC_DIR) libft/inc/ MLX42/include/MLX42/
LIB_DIR				= libft $(BREW_PATH)/opt/glfw/lib/ MLX42/build/

# Flags setup
CC		= cc
OPT		= 0
LIB		= ft glfw mlx42
WARN	= all extra error
EXTRA	= -MP -MMD -g
FWK		= OpenGL Cocoa IOKit

# Compiler flags
override CFLAGS 	+= $(EXTRA) $(OPT:%=-O%) $(INC_DIR:%=-I%) $(WARN:%=-W%)
# Linker flags
override LDFLAGS	+= $(LIB_DIR:%=-L%) $(LIB:%=-l%) $(FWK:%=-framework %)

# Sources
SRCS_MANDATORY =			\
state.c						\
hook.c						\
image.c						\
view.c						\
view_draw.c					\
vec2f.c						\
vec2f_ops.c					\
vector.c					\
vector_extend.c				\
vector_position.c			\
vector_remove.c				\
vector_reserve.c			\
scene.c						\
scene_read.c				\
scene_set_textures.c		\
scene_set_colors.c			\
scene_set_options.c			\
map.c						\
map_read.c					\
map_validate.c				\
line.c						\
line_textured.c				\
ray.c						\
ray_util.c					\
player.c					\
texture.c					\
scene_print_error.c			\
util.c						\
main.c

SRCS_BONUS =				\
minimap_bonus.c				\
minimap_wall_draw_bonus.c			\
scene_set_options_bonus.c	\
scene_set_textures_bonus.c	\
mouse_bonus.c						\
texture_bonus.c					\
player_bonus.c						\
state_bonus.c

ifeq ($(BONUS_FEATURES), 1)
	SRCS = $(SRCS_MANDATORY) $(SRCS_BONUS)
	override CFLAGS += -D BONUS_FEATURES
else
	SRCS = $(SRCS_MANDATORY)
endif

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(OBJ_DIR)%.d)

.PHONY: all clean fclean re obj_dir $(LIBFT) norm init bonus

all: $(NAME)

$(MLX42):
	@-test -f MLX42/README.md || make init
	cd MLX42 && cmake -B build && cmake --build build -j4

$(LIBFT):
	@-test -f libft/README.md || make init
	make -C libft OBJ_DIR="../obj/"

init:
	git submodule update --init
	cd MLX42 && git checkout a2f6f23

$(NAME): $(OBJS) | $(LIBFT)
	@echo ""
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)%.o: %.c | obj_dir $(MLX42)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus:
	make BONUS_FEATURES=1

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
	rm -rf MLX42/build

norm:
	norminette src | grep -v OK

debug: fclean
	make -C libft OBJ_DIR="../obj/" FLAGS="-g -fsanitize=address"
	make $(NAME) CFLAGS="-g -fsanitize=address"

vpath %.c $(SRC_DIR)
-include $(DEPS)
