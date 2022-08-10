# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 13:39:59 by blaurent          #+#    #+#              #
#    Updated: 2022/08/10 13:45:44 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

FLAGS		= -Wall -Wextra -Werror

MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit

FILES		= map.c \
				move.c \
				path.c \
				render.c \
				so_long.c \
				mylib/ft_printf/ft_fprintf.c \
				mylib/ft_printf/ft_fprint_c.c \
				mylib/ft_printf/ft_fprint_p.c \
				mylib/ft_printf/ft_fprint_s.c \
				mylib/ft_printf/ft_fprint_u.c \
				mylib/ft_printf/ft_fprint_x.c \
				mylib/ft_printf/ft_fprint_di.c \
				mylib/libft/ft_bzero.c \
				mylib/libft/ft_calloc.c \
				mylib/libft/ft_freetab.c \
				mylib/libft/ft_putaddr.c \
				mylib/libft/ft_putchar_fd.c \
				mylib/libft/ft_putnbr_base.c \
				mylib/libft/ft_putnbr_fd.c \
				mylib/libft/ft_putstr_fd.c \
				mylib/libft/ft_split.c \
				mylib/libft/ft_strdup.c \
				mylib/libft/ft_strjoin.c \
				mylib/libft/ft_strlen.c \
				mylib/libft/gnl.c \

OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(MLXFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re