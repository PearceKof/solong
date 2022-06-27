# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 15:35:28 by blaurent          #+#    #+#              #
#    Updated: 2022/02/07 15:35:28 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= mylib.a

FLAGS		= -Wall -Wextra -Werror

FILES		= ft_printf/ft_printf.c \
				ft_printf/ft_print_c.c \
				ft_printf/ft_print_p.c \
				ft_printf/ft_print_s.c \
				ft_printf/ft_print_u.c \
				ft_printf/ft_print_x.c \
				ft_printf/ft_print_di.c \
				gnl/gnl.c \
				gnl/gnl_utils.c \

OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	cp libft/libft.a $(NAME)
	ar crs $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re