# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 13:39:59 by blaurent          #+#    #+#              #
#    Updated: 2022/07/18 16:27:03 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

FLAGS		= -Wall -Wextra -Werror

MLXFLAGS	= -Imlx -lmlx -framework OpenGL -framework AppKit

FILES		= map.c \
				so_long.c \
				render.c \
				move.c \
				mylib/ft_printf/ft_printf.c \
				mylib/ft_printf/ft_print_c.c \
				mylib/ft_printf/ft_print_p.c \
				mylib/ft_printf/ft_print_s.c \
				mylib/ft_printf/ft_print_u.c \
				mylib/ft_printf/ft_print_x.c \
				mylib/ft_printf/ft_print_di.c \
				mylib/gnl/gnl.c \
				mylib/gnl/gnl_utils.c \
				mylib/libft/ft_atoi.c \
				mylib/libft/ft_bzero.c \
				mylib/libft/ft_calloc.c \
				mylib/libft/ft_freetab.c \
				mylib/libft/ft_itoa.c \
				mylib/libft/ft_memchr.c \
				mylib/libft/ft_memcmp.c \
				mylib/libft/ft_memcpy.c \
				mylib/libft/ft_memmove.c \
				mylib/libft/ft_memset.c \
				mylib/libft/ft_putaddr.c \
				mylib/libft/ft_putchar_fd.c \
				mylib/libft/ft_putendl_fd.c \
				mylib/libft/ft_putnbr_base.c \
				mylib/libft/ft_putnbr_fd.c \
				mylib/libft/ft_putstr_fd.c \
				mylib/libft/ft_putstr.c \
				mylib/libft/ft_split.c \
				mylib/libft/ft_strchr.c \
				mylib/libft/ft_strdup.c \
				mylib/libft/ft_striteri.c \
				mylib/libft/ft_strjoin.c \
				mylib/libft/ft_strlcat.c \
				mylib/libft/ft_strlcpy.c \
				mylib/libft/ft_strlen.c \
				mylib/libft/ft_strmapi.c \
				mylib/libft/ft_strncmp.c \
				mylib/libft/ft_strnstr.c \
				mylib/libft/ft_strrchr.c \
				mylib/libft/ft_strstr.c \

OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re