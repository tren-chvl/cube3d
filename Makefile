NAME    := cub3D
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g
LDFLAGS := -Llibft -Lminilibx-linux -L/usr/lib -lXext -lX11 -lm -lz -lft -lmlx
INCLUDES:= -Iincludes -Ilibft/includes -I/usr/include -Iminilibx-linux 

SRC_DIR := src
OBJ_DIR := obj

SRCS    := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS    := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR := libft
LIBFT     := $(LIBFT_DIR)/libft.a

MLX_DIR   := minilibx-linux
MLX       := $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
