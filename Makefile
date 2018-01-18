# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobion <arobion@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 10:20:11 by arobion           #+#    #+#              #
#    Updated: 2018/01/18 14:49:23 by arobion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME1 = checker

SRC1 =	checker.c \
		check_parsing.c \
		check_do_instr.c \
		check_do_instr2.c \
		check_do_instr3.c \
		ft_free.c

OBJ1 = $(SRC1:.c=.o)

NAME2 = push_swap

SRC2 =	stock2.c \
		push_swap.c \
		push_swap2.c \
		check_parsing.c \
		push_do_instr.c \
	 	push_do_instr2.c \
	 	push_do_instr3.c \
		quick_sort_v3.c \
		quick_less_ten.c \
		ft_sort_three.c \
		reput_to_pile1.c \
		reput_to_pile1_annexes.c \
		optimize_instr.c \
		optimize_instr2.c \
		find_road_b.c \
		find_road_a.c \
		find_smallest.c \
		find_biggest.c \
		find_special_numbers.c \
		find_top_for_a.c \
		small_quick.c \
		big_quick.c \
		big_quick2.c \
		check_do_instr2.c \
		ft_free.c

OBJ2 = $(SRC2:.c=.o)

LIB = libft/libft.a

INCLUDES = libft/

RED = \033[31m
GREEN = \033[32m
END = \033[0m

all : $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(LIB)
	@echo "$(GREEN)CHECKER READY$(END)"

$(NAME2): $(OBJ2)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) $(LIB)
	@echo "$(GREEN)PUSH_SWAP READY$(END)"

%.o: %.c 
	$(CC) -c $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	make clean -C libft
	/bin/rm -f $(OBJ1) $(OBJ2)
	@echo "$(RED)CHECKER OBJECTS REMOVE$(END)"
	@echo "$(RED)PUSH_SWAP OBJECTS REMOVE$(END)"

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME1) $(NAME2)
	@echo "$(RED)CHECKER REMOVE$(END)"
	@echo "$(RED)PUSH_SWAP REMOVE$(END)"

re: fclean all

.PHONY: all clean fclean re
