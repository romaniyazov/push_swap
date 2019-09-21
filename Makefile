# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/09/21 17:07:07 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Ilibft -Ilibstacks
LIBFT		=	-Llibft -lft
LIBSTACKS	=	-Llibstacks -lstacks
SRC			=	push_swap.c \
				args_to_ilist.c \
				index_ilist.c \
				is_sorted.c \
				operations.c \
				partition_sort.c \
				sort_three.c \
				sort_five.c \
				ilistmisc.c \
				ilists.c \
				optimize_ops.c \
				ilistdel.c \
				r_rr.c
OBJ			=	$(SRC:%.c=%.o)

all: DEPS $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIBFT) $(LIBSTACKS) -o $(NAME)

%.o: %.c %.h

DEPS:
	make -C libstacks/
	make -C libft/
	make -C checkerr/
	cp -f checkerr/checker .

clean:
	make -C libft $@
	make -C libstacks $@
	make -C checkerr $@
	rm -f $(OBJ)

fclean: clean
	make -C libft $@
	make -C libstacks $@
	make -C checkerr $@
	rm -f checker
	rm -f $(NAME)

re: fclean all
