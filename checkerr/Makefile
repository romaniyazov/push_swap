# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/09/21 18:03:56 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	checker
FLAGS		=	-Wall -Werror -Wextra -g
LIBFT		=	-I../libft -L../libft -lft
LIBSTACKS	=	-I../libstacks -L../libstacks -lstacks
SRC			=	checker.c \
				args_to_list.c \
				print_stacks.c \
				is_sorted.c \
				terminate.c
OBJ			=	$(SRC:%.c=%.o)

$(NAME):
	@gcc $(FLAGS) $(LIBFT) $(LIBSTACKS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
