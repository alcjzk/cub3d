# Targets
NAME = $(BIN_DIR)libft.a

# Directories
SRC_DIR		= $(sort $(dir $(wildcard src/*/))) src/
INC_DIR		= inc/ $(SRC_DIR)
OBJ_DIR		= obj/
BIN_DIR		= ./

# Sources
SRCS = \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_isspace.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strtonum.c \
ft_strcmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
ft_mempos.c \
get_next_line.c \
gnl_outbuf.c \
gnl_readbuf.c \
ft_max.c \
ft_abs.c \
ft_tostr.c \
fmtblock.c \
ft_digits.c \
fmt.c \
fmt_hex.c \
fmt_int.c \
fmt_parse.c \
fmt_ptr.c \
fmt_str.c \
fmt_util.c \
ft_printf.c

# Flags setup
CC				= cc
OPT				= 3
WARN			= all extra error
override EXTRA	+= -MP -MMD

# Compiler flags
override CFLAGS 	+= $(EXTRA) $(OPT:%=-O%) $(INC_DIR:%=-I%) $(WARN:%=-W%)

################################################################################
# CONFIG #######################################################################
################################################################################

.PHONY: all clean fclean re debug d
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(OBJ_DIR)%.d)

################################################################################
# RULES ########################################################################
################################################################################

# Default rule
all: $(NAME)

# Objects
$(OBJS): $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Target
$(NAME): $(OBJS) | $(BIN_DIR)
	ar -rcs $@ $?

# Cleanup
clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

# Debug
debug:
	make fclean
	make all FLAGS="-g -fsanitize=address"

# Aliases
re: fclean all
d: debug

# Dir creation
$(OBJ_DIR) $(BIN_DIR):
	@mkdir $@

vpath %.c src/
-include $(DEPS)