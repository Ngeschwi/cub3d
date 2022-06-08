# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 16:55:28 by ngeschwi          #+#    #+#              #
#    Updated: 2022/06/08 15:21:58 by ngeschwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c \
			src/basic_function/ft_putstr.c \
			src/basic_function/ft_strdup.c \
			src/basic_function/ft_strlen.c \
			src/basic_function/ft_substr.c \
			src/basic_function/ft_strjoin.c \
			src/error/ft_error_exit.c \
			src/gnl/get_next_line.c \
			src/gnl/get_next_line_utils.c \
			src/parse/ft_parse_map.c \
			src/parse/ft_parse_map2.c \
			src/parse/ft_parse_map3.c \
			src/parse/ft_parse_map4.c \
			src/game/ft_lunch_game.c

OBJS	= $(SRCS:.c=.o)

NAME	= cub3d

CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3
LIBS	= -LminilibX -lmlx -framework OpenGL -framework AppKit -lm
MLX		= libmlx.dylib
LINK	= -Iincludes -IminilibX

all:		$(NAME)

%.o : %.c
	${CC} ${CFLAGS} ${LINK} -o $@ -c $<

$(NAME):	${MLX} $(OBJS)
		${CC} ${CFLAGS} $(OBJS) ${LINK} ${LIBS} -o $(NAME)

$(MLX) :
		$(MAKE) -C minilibX
		@cp minilibX/$(MLX) .

$(OBJS):	includes/get_next_line.h includes/cub3d.h minilibX/mlx.h

clean:
		$(MAKE) -C minilibX clean
		$(RM) libmlx.dylib
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
