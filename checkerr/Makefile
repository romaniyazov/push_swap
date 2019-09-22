# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/09/22 13:53:58 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	checker
CC			=	GCC
CFLAGS		=	-Wall -Werror -Wextra -I ../libft -I../libstacks
LIBFT		=	-L../libft -lft
LIBSTACKS	=	-L../libstacks -lstacks
SRC			=	checker.c \
				args_to_list.c \
				print_stacks.c \
				is_sorted.c \
				terminate.c
OBJ			=	$(SRC:%.c=%.o)

all: DEPS $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIBFT) $(LIBSTACKS) -o $(NAME)

DEPS:
	make -C ../libft/
	make -C ../libstacks/

%.o: %.c %.h

clean:
	make -C ../libft $@
	make -C ../libstacks $@
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
