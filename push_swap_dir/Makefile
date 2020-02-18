# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 06:08:46 by bdebbie           #+#    #+#              #
#    Updated: 2020/01/13 07:16:22 by bdebbie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = case.c \
	  convert_str_array.c \
	  decision.c \
	  find_med_10.c \
	  find_med_and_min_max.c \
	  method.c \
	  push_swap.c \
	  proverka_str.c \
	  solution_less_3.c \
	  solution_less_10.c \
	  solution_less_100.c \
	  solution_less_100_cont.c \
	  solution_other.c \
	  solution_other_cont.c \
	  validation.c
OBJ = $(patsubst %.c,%.o, $(SRC))
NAME = push_swap
INC = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I $(INC)

$(OBJ): %.o:%.c
	@gcc -Wall -Wextra -Werror -c $< -I $(INC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
