# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 13:39:59 by blaurent          #+#    #+#              #
#    Updated: 2022/06/24 13:43:35 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

FLAGS		= -Wall -Wextra -Werror

FILES		= map.c \
				so_long.c

OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	make -C mylib/
	cp mylib/libft.a $(NAME)
	ar crs $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -Imlx -c $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re