SRC =	src/main.c \
		src/parsing.c\
		src/image.c\
		src/init_images.c\
		src/moves.c\
		src/checker.c\
		src/errors.c\
		./libft/srcs/get_next_line.c \
		./libft/srcs/get_next_line_utils.c \

SRC_B =	src_bonus/main_bonus.c \
		src_bonus/parsing_bonus.c\
		src_bonus/init_images_bonus.c\
		src_bonus/errors_bonus.c\
		src_bonus/image_bonus.c\
		src_bonus/moves_bonus.c\
		src_bonus/checker_bonus.c\
		src_bonus/animation_bonus.c \
		src_bonus/simple_errors_bonus.c\
		src_bonus/utils_bonus.c\
		./libft/srcs/get_next_line.c \
		./libft/srcs/get_next_line_utils.c \

OBJS_B = objs_bonus/main_bonus.o \
		objs_bonus/parsing_bonus.o\
		objs_bonus/image_bonus.o\
		objs_bonus/init_images_bonus.o\
		objs_bonus/errors_bonus.o\
		objs_bonus/moves_bonus.o\
		objs_bonus/checker_bonus.o\
		objs_bonus/animation_bonus.o\
		objs_bonus/simple_errors_bonus.o\
		objs_bonus/utils_bonus.o\
		./libft/srcs/get_next_line.o \
		./libft/srcs/get_next_line_utils.o \

OBJS =	objs/main.o \
		objs/parsing.o\
		objs/image.o\
		objs/moves.o\
		objs/init_images.o\
		objs/checker.o\
		objs/errors.o\
		./libft/srcs/get_next_line.o \
		./libft/srcs/get_next_line_utils.o \

NAME = so_long

NAME_BONUS = so_long_bonus

CC = gcc

INC = include/

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g #-g3 -fsanitize=address

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFLAGS = -L libft -lft

all : ${NAME}

bonus : ${NAME_BONUS}

objs/%.o : src/%.c
	mkdir -p ./objs
	$(CC) $(CFLAGS) -I${INC} -c $< -o $@

objs_bonus/%.o : src_bonus/%.c
	mkdir -p ./objs_bonus
	$(CC) $(CFLAGS) -I${INC} -c $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I${INC} -c $< -o $@

${NAME} : ${OBJS} $(LIB)
	make -C ./libft
	make -C ./mlx_linux
	$(CC) $(CFLAGS) ${OBJS} -D LINUX ${MLXFLAGS} ${LIBFLAGS} -o ${NAME}

${NAME_BONUS} : ${OBJS_B}
	make -C ./libft
	make -C ./mlx_linux
	$(CC) $(CFLAGS) ${OBJS_B} -D LINUX ${MLXFLAGS} ${LIBFLAGS} -o ${NAME_BONUS}


clean:
		$(RM) ${OBJS} $(OBJ_B)
		$(RM) ./objs
		make clean -C ./mlx_linux
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)
		$(RM) ./mlx_linux/libmlx_Linux.a
		$(RM) ./mlx_linux/libmlx.a
		$(RM) ./libft/libft.a

malloc_test:	$(OBJS) ./libft/libft.a ./mlx_linux/libmlx_Linux.a
				$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} $(MLXFLAGS) ./libft/libft.a ./mlx_linux/libmlx_Linux.a -L. -lmallocator

re:	fclean all

#Ajoute re_bonus et .PHONY