# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/09/13 17:28:42 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
FLAGS		=	-Wall -Werror -Wextra
SRC			=	push_swap.c \
				args_to_ilist.c \
				index_ilist.c \
				is_sorted.c \
				operations.c \
				partition_sort.c \
				sort_three.c \
				ilistmisc.c \
				ilists.c \
				optimize_ops.c

$(NAME):
	@gcc $(FLAGS) $(SRC) -Ilibft -Llibft -lft -Ilibstacks -Llibstacks -lstacks -o $(NAME)

all: $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all
