# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/09/15 22:52:03 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
FLAGS		=	-c -Wall -Werror -Wextra
LIBFT		=	-Ilibft -Llibft -lft
LIBSTACKS	=	-Ilibstacks -Llibstacks -lstacks
SRC			=	push_swap.c \
				args_to_ilist.c \
				index_ilist.c \
				is_sorted.c \
				operations.c \
				partition_sort.c \
				sort_three.c \
				sort_six.c \
				ilistmisc.c \
				ilists.c \
				optimize_ops.c \
				ilistdel.c \
				r_rr.c
OBJ			=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): obj
	@make -C libstacks
	@make -C libft
	@make -C checker
	@gcc $(OBJ) -Llibft -lft -Llibstacks -lstacks -o $(NAME)

obj:
	@gcc $(FLAGS) $(SRC) -Ilibft -Ilibstacks

clean:
	@make -C libft $@
	@make -C libstacks $@
	@make -C checker $@
	@rm -f $(OBJ)

fclean: clean
	@make -C libft $@
	@make -C libstacks $@
	@make -C checker $@
	@rm -f $(NAME)

re: fclean all
