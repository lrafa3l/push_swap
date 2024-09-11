# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrafael <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 09:23:51 by lrafael           #+#    #+#              #
#    Updated: 2024/09/11 13:37:12 by lrafael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
OBJS_DIR = obj
LIBFT_DIR = ./libft
INCLUDE = -Iincs

SRCS = $(SRCS_DIR)/ps_main.c			\
		$(SRCS_DIR)/ps_init_stack.c		\
		$(SRCS_DIR)/ps_stack_utils.c	\
		$(SRCS_DIR)/ps_check.c			\
		$(SRCS_DIR)/ps_operations.c	    \
		$(SRCS_DIR)/ps_roperations.c	\
		$(SRCS_DIR)/ps_algorithm.c		\
		$(SRCS_DIR)/ps_free.c

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
LIB = -L$(LIBFT_DIR) -lft

BOLD = \033[1m
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m
CLEAR = \033c

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(OBJS) $(LIB) -o $(NAME)
	@echo "$(CLEAR)"
	@echo "$(GREEN)$(BOLD)Now you can push and swap ;)$(RESET)\n"

n:
	norminette

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "$(CLEAR)"
	@echo "$(RED)$(BOLD)Objects Deleted!$(RESET)\n"

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(CLEAR)"
	@echo "$(RED)$(BOLD)Everything Deleted$(RESET)\n"

re: fclean all

.PHONY: all n clean fclean re
