# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrafael <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 09:23:51 by lrafael           #+#    #+#              #
#    Updated: 2024/09/15 14:17:40 by lrafael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Mandatory Part
NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJS_DIR = obj
LIBFT_DIR = ./libft
INCLUDE = -Iincs

SRCS = $(SRCS_DIR)/ps_main.c			\
		$(SRCS_DIR)/ps_stack_init.c		\
		$(SRCS_DIR)/ps_check.c			\
		$(SRCS_DIR)/ps_stack_utils.c	\
		$(SRCS_DIR)/ps_stack_utils+.c	\
		$(SRCS_DIR)/ps_operations.c	    \
		$(SRCS_DIR)/ps_roperations.c	\
		$(SRCS_DIR)/ps_sorting.c	    \
		$(SRCS_DIR)/ps_sorting_utils.c  \
		$(SRCS_DIR)/ps_sorting_utils+.c	\
		$(SRCS_DIR)/ps_free.c

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIB = -L$(LIBFT_DIR) -lft
CLEAR = \033c

#Bonus Part
NAME_BONUS = checker
SRCS_BONUS_DIR = srcs_bonus
OBJS_BONUS_DIR = obj_bonus
INCLUDE_BONUS = -Iincs_bonus

SRCS_BONUS = $(SRCS_BONUS_DIR)/ps_main_bonus.c 					\
				$(SRCS_BONUS_DIR)/ps_check_bonus.c 				\
				$(SRCS_BONUS_DIR)/ps_stack_init_bonus.c			\
				$(SRCS_BONUS_DIR)/ps_stack_utils_bonus.c		\
				$(SRCS_BONUS_DIR)/ps_checker_utils_bonus.c 		\
				$(SRCS_BONUS_DIR)/ps_checker_init_bonus.c 		\
				$(SRCS_BONUS_DIR)/ps_operations_bonus.c			\
				$(SRCS_BONUS_DIR)/ps_roperations_bonus.c		\
				$(SRCS_BONUS_DIR)/ps_rev_roperations_bonus.c	\
				$(SRCS_BONUS_DIR)/ps_cleanup_bonus.c

OBJS_BONUS = $(SRCS_BONUS:$(SRCS_BONUS_DIR)/%.c=$(OBJS_BONUS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(OBJS) $(LIB) -o $(NAME)
	@echo "$(CLEAR)"

bonus: $(NAME_BONUS)

$(OBJS_BONUS_DIR)/%.o: $(SRCS_BONUS_DIR)/%.c
	@mkdir -p $(OBJS_BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(OBJS_BONUS) $(LIB) -o $(NAME_BONUS)
	@echo "$(CLEAR)"

n:
	norminette

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_BONUS_DIR)
	@echo "$(CLEAR)"

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(CLEAR)"

re: fclean all

.PHONY: all n clean fclean re
