# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkremen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:15:35 by vkremen           #+#    #+#              #
#    Updated: 2019/01/12 18:57:17 by vkremen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

FLAGS = -Wall -Werror -Wextra

SRC_PUSH_SWAP = ./sources_push_swap/main_push_swap.c\
				./sources_push_swap/fill_stack.c\
				./sources_push_swap/support_function.c\
				./sources_push_swap/operations.c\
				./sources_push_swap/helpful_function.c\
				./sources_push_swap/checking.c\
				./sources_push_swap/algorithm_for_one_hundred_nums.c\
				./sources_push_swap/algorithm_for_three_num.c\
				./sources_push_swap/algorithm_until_six.c\
				./sources_push_swap/algorithm_from_six_until_one_hundred.c\
				./sources_push_swap/algorithm_from_one_hundred.c

SRC_CHECKER =   ./sources_checker/main_checker.c\
				./sources_checker/operations.c\
				./sources_checker/helpful_function.c\
				./sources_checker/checking.c\
				./sources_checker/sort_tab.c

OB_PUSH_SWAP = $(SRC_PUSH_SWAP:%.c=%.o)

OB_CHECKER = $(SRC_CHECKER:%.c=%.o)

all: $(PUSH_SWAP) $(CHECKER)

%.o:%.c
	@gcc -c $(FLAGS) $< -o $@

$(PUSH_SWAP): $(OB_PUSH_SWAP)
	@make -C libft
	@gcc $(OB_PUSH_SWAP) libft/libft.a -o $(PUSH_SWAP)

$(CHECKER): $(OB_CHECKER)
	@gcc $(OB_CHECKER) libft/libft.a -o $(CHECKER)

clean: 
	@make clean -C libft
	@rm -f $(OB_PUSH_SWAP)
	@rm -f $(OB_CHECKER)

fclean: clean
	@make fclean -C libft
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)

re: fclean all
