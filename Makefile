NAME = cub3D

SRCS	=	change_dir.c			\
			check_elements.c		\
			check_file.c			\
			check_map.c				\
			create_map.c			\
			culc_distance.c			\
			destroy.c				\
			draw_minimap.c			\
			draw.c					\
			error.c					\
			get_next_line_utils.c	\
			get_next_line.c			\
			main.c					\
			next_frame.c			\
			check_distance.c		\
			set_culc_data.c			\
			choice_distance.c		\
			angle_multiple_ninety.c	\

INCLUDE_DIR = ./include
SRCDIR = ./srcs/
OBJDIR = ./obj/
MLX_DIR = ./mlx/

LIBFT_DIR = ./libft/
LIBFT_A = $(LIBFT_DIR)libft.a

OBJS = $(SRCS:%.c=$(OBJDIR)%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I include -I mlx

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

all: $(LIBFT_A) $(OBJDIR) $(NAME)

$(NAME): $(LIBFT_A) $(OBJDIR) $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAG) -o $(NAME) $(LIBFT_A) $(OBJS) ./mlx/libmlx.a -L./mlx/
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(OBJDIR) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
