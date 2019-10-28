# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 16:54:48 by cbretagn          #+#    #+#              #
#    Updated: 2019/10/28 17:08:16 by cbretagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK		= checker

SORT		= push_swap

VISU		= preview

UTIL_PATH	= utility

CHECK_PATH	= check

SORT_PATH	= sort

VISU_PATH	= visu

OBJ_PATH_CHECK	= obj_check

OBJ_PATH_UTIL	= obj_util

OBJ_PATH_SORT	= obj_sort

OBJ_PATH_VISU	= obj_visu

UTIL_NAME	= create_pile.c\
			  push.c\
			  swap.c\
			  rotation.c\
			  error_checker.c\
			  arg_str.c
			  
SORT_NAME	= sort_algo.c\
			  sort_algo_utility.c\
			  sort_algo2.c\
			  cheese.c\
			  instruction_handling.c\
			  main.c

CHECK_NAME	= checker.c\
			  get_next_line.c

VISU_NAME	= main.c\
			  preview.c\
			  init_fun.c\
			  sdl_utility.c\
			  gen_utility.c

OBJ_UTIL_NAME	:= $(UTIL_NAME:.c=.o)

OBJ_SORT_NAME	:= $(SORT_NAME:.c=.o)

OBJ_CHECK_NAME	:= $(CHECK_NAME:.c=.o)

OBJ_VISU_NAME	:= $(VISU_NAME:.c=.o)

SRC_UTIL	= $(addprefix $(UTIL_PATH)/,$(UTIL_NAME))

SRC_CHECK	= $(addprefix $(CHECK_PATH)/,$(CHECK_NAME))

SRC_SORT	= $(addprefix $(SORT_PATH)/,$(SORT_NAME))

SRC_VISU	= $(addprefix $(VISU_PATH)/,$(VISU_NAME))

OBJ_UTIL	= $(addprefix $(OBJ_PATH_UTIL)/,$(OBJ_UTIL_NAME))

OBJ_CHECK	= $(addprefix $(OBJ_PATH_CHECK)/,$(OBJ_CHECK_NAME))

OBJ_SORT	= $(addprefix $(OBJ_PATH_SORT)/,$(OBJ_SORT_NAME))

OBJ_VISU	= $(addprefix $(OBJ_PATH_VISU)/,$(OBJ_VISU_NAME))

LIB_PATH	= libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

.PHONY		: all clean fclean re display analyze

all			: $(CHECK) $(SORT)

display		: $(VISU)

$(VISU)			: $(OBJ_UTIL) $(OBJ_VISU)
	make -C ./libft/
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_PATH) `sdl2-config --libs` -lpthread

$(CHECK)		: $(OBJ_UTIL) $(OBJ_CHECK)
	make -C ./libft/
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_PATH)

$(SORT)			: $(OBJ_UTIL) $(OBJ_SORT)
	make -C ./libft/
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_PATH)

$(OBJ_PATH_VISU)/%.o	: $(VISU_PATH)/%.c
		mkdir $(OBJ_PATH_VISU) 2> /dev/null || true
		$(CC) $(CFLAGS) -o $@ -c $< `sdl2-config --cflags`

$(OBJ_PATH_UTIL)/%.o	: $(UTIL_PATH)/%.c
		mkdir $(OBJ_PATH_UTIL) 2> /dev/null || true
		$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH_SORT)/%.o	: $(SORT_PATH)/%.c
		mkdir $(OBJ_PATH_SORT) 2> /dev/null || true
		$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH_CHECK)/%.o	:	$(CHECK_PATH)/%.c
		mkdir $(OBJ_PATH_CHECK) 2> /dev/null || true
		$(CC) $(CFLAGS) -o $@ -c $<

analyze		:
	$(CC) -fsyntax-only $(CFLAGS) $(SRC)
	$(CC) --analyze $(CFLAGS) $(SRC)

clean		:
	rm -f $(OBJ_UTIL)
	rm -f $(OBJ_CHECK)
	rm -f $(OBJ_SORT)
	make clean -C ./libft/
	rmdir $(OBJ_PATH_UTIL) 2> /dev/null || true
	rmdir $(OBJ_PATH_CHECK) 2> /dev/null || true
	rmdir $(OBJ_PATH_SORT) 2> /dev/null || true

fclean		: clean
	rm -f $(CHECK) $(SORT)
	make fclean -C ./libft/

re 			: fclean all
