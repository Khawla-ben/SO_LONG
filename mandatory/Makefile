# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 16:11:47 by kben-ham          #+#    #+#              #
#    Updated: 2023/02/13 14:51:14 by kben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJECT = $(MY_FILES:.c=.o)

CC = cc -Wall -Wextra -Werror

MY_FILES =	check_maps.c get_next_line.c get_next_line_utils.c printf.c so_long.c win.c check.c move_player.c utils.c fold.c

MLX = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

%.o: %.c so_long.h get_next_line.h
	$(CC) -o $@ -c  $< 

$(NAME): $(OBJECT) 
	$(CC) $(MLX) $^ -o $(NAME)

clean:
	rm -f $(OBJECT)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all