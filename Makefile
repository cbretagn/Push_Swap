# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 16:54:48 by cbretagn          #+#    #+#              #
#    Updated: 2019/10/11 18:43:49 by cbretagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker

SRC_PATH	= utility

OBJ_PATH	= obj

SRC_NAME	= create_pile.c\
			  print_piles.c\
			  push.c\
			  swap.c\
			  rotation.c\
			  error_checker.c\
			  checker.c\
			  get_next_line.c\
			  instruction_handling.c\
			  quicksort.c\
			  sort_algo.c\
			  sort_algo_utility.c\
			  cheese.c\
			  simple_sort.c

OBJ_NAME	:= $(SRC_NAME:.c=.o)

SRC			= $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB_PATH	= libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

.PHONY		: all clean fclean re

all			: $(NAME)

$(NAME)		: $(OBJ)
	make -C ./libft/
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

analyze		:
	$(CC) -fsyntax-only $(CFLAGS) $(SRC)
	$(CC) --analyze $(CFLAGS) $(SRC)

clean		:
	rm -f $(OBJ)
	make clean -C ./libft/
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean		: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re 			: fclean all
