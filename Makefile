NAME = CUB3D
CC = cc
SRC = main.c \
	 ./get_next_line/get_next_line.c \
	 ./parsing/return_map.c \
	 ./parsing/parse_outils.c \
	 ./parsing/lexer.c \
	 ./parsing/pars_outils1.c \
	 ./parsing/take_map.c \
	 ./parsing/linked_outils.c \
	 ./parsing/check_map.c \
	 ./parsing/check_map1.c \
	 ./parsing/norm_pars1.c \
	 ./parsing/norm_pars2.c \
	 ./2DMAP/get_info.c \
	 ./2DMAP/drw_2d_map.c \
	 ./genrate3d.c \
	 ./generate3d_2.c \
	 ./2DMAP/norm_2d_map.c \
	 norm1.c
FLAGS = -Wall -Wextra -Werror #-fsanitize=address
FLA = -lmlx -framework OpenGL -O3 -framework AppKit #-fsanitize=address
ARG = -o
all : $(NAME)

$(NAME): $(SRC)
	make -C ./libftt
	$(CC) $(FLAGS) $(FLA) $(SRC) $(ARG) $(NAME) ./libftt/libft.a

clean :
	cd libftt && rm -rf *.o
	rm -rf CUB3D.dSYM
	rm -f $(NAME)

fclean : clean

re: fclean all