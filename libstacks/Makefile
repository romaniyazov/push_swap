# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/09/15 19:28:08 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libstacks.a
FLAGS		=	-Wall -Werror -Wextra -c
SRC			=	stacks.c \
				operations.c \
				stackdel.c
OBJ			=	$(SRC:%.c=%.o)

$(NAME):
	@gcc $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
