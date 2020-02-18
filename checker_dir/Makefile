# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 03:20:54 by bdebbie           #+#    #+#              #
#    Updated: 2020/01/13 07:15:53 by bdebbie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = convert_str_in_checker.c \
	  function_1.c \
	  method_a.c \
	  checker.c \
	  proverka_str_in_checker.c \
	  ft_strcmp.c \
	  validation_in_checker.c
OBJ = $(patsubst %.c,%.o, $(SRC))
NAME = checker
INC = checker.h

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
