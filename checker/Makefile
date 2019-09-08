# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/09/08 20:02:38 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	checker
FLAGS		=	-Wall -Werror -Wextra
LIBFT		=	-I../libft -L../libft -lft
LIBSTACKS	=	-I../libstacks -L../libstacks -lstacks
SRC			=	checker.c \
				args_to_list.c \
				print_stacks.c
OBJ			=	$(SRC:%.c=%.o)

$(NAME):
	@gcc $(FLAGS) $(LIBFT) $(LIBSTACKS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
