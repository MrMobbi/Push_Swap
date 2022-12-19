# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 12:18:20 by mjulliat          #+#    #+#              #
#    Updated: 2022/12/17 19:25:10 by mjulliat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###

CC			= gcc -g
FLAGS		= -Wall -Werror -Wextra
FRAMEWORK	= -framework OpenGL -framework AppKit

	### EXECUTABLE ###

NAME		= push_swap
NAME_BONUS	= checker

	### INCLUDES ###

SRCS_PATH	= srcs
OBJS_PATH	= objs

SRCB_PATH	= srcs
OBJB_PATH	= objs_bonus

HEADERS		= incl
PRINTF		= ft_printf
GNL			= gnl

	### SOURCE FILE ###

SOURCES		= main.c\
			  utils.c\
			  utils_2.c\
			  ft1_error.c\
			  ft1_error2.c\
			  ft1_init_env.c\
			  ft1_add_index.c\
			  ft1_add_index2.c\
			  ft1_split.c\
			  ft1_one_string.c\
			  ft2_solver.c\
			  ft2_solver2.c\
			  ft2_step1.c\
			  ft2_solve_b.c\
			  ft2_swap_and_push.c\
			  ft2_rotate_and_reverse.c

	### BONUS FILE ###

BONUS		= main_bonus.c\
			  utils.c\
			  utils_2.c\
			  utils_bonus.c\
			  ft1_error.c\
			  ft1_error2.c\
			  ft1_init_env.c\
			  ft1_add_index.c\
			  ft1_add_index2.c\
			  ft1_split.c\
			  ft1_one_string.c\
			  ft2_solver.c\
			  ft2_solver2.c\
			  ft2_step1.c\
			  ft2_solve_b.c\
			  ft2_swap_and_push.c\
			  ft2_rotate_and_reverse.c\
			  ft3_swap_and_push.c\
			  ft3_rotate.c\
			  ft3_reverse.c


	### OBJETCTS ###

SRCS		= $(addprefix $(SRCS_PATH)/,$(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/,$(SOURCES:.c=.o))

SRCB		= $(addprefix $(SRCB_PATH)/,$(BONUS))
OBJB		= $(addprefix $(OBJB_PATH)/,$(BONUS:.c=.o))

	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
NOC			= \033[0m
WHITE		= \033[1;37m

	### RULES ###

all:		tmp printf $(NAME)

$(NAME):	$(OBJS)
			@echo "$(BLUE)######## Obect file Created ######### $(WHITE)"
			$(CC) $(FLAGS) -L$(PRINTF) -lftprintf $(FRAMEWOKR) -o $@ $^ 
			@echo "$(GREEN)######## Project Compilated ######## $(WHITE)"

printf:
			@make -sC $(PRINTF)
			@cp ft_printf/libftprintf.a .
			@echo "$(CYAN)######## LIBFTPRINTF.A Created ######## $(WHITE)"

tmp:		
			@mkdir -p objs

bonus:		tmp_bonus gnl printf $(NAME_BONUS)

$(NAME_BONUS):	$(OBJB)
				@echo "$(BLUE)######## Obect file Created ######### $(WHITE)"
				$(CC) $(FLAGS) -L$(PRINTF) -L$(GNL) -lftprintf -lgnl $(FRAMEWOKR) -o $@ $^ 
				@echo "$(GREEN)######## Project Compilated ######## $(WHITE)"

gnl:
			@make -sC $(GNL)
			@cp gnl/libgnl.a .
			@echo "$(CYAN)######## LIBGNL.A Created ######## $(WHITE)"

tmp_bonus:	
			@mkdir -p objs_bonus

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS) -I$(PRINTF) -c $< -o $@

$(OBJB_PATH)/%.o:	$(SRCB_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS) -I$(PRINTF) -I$(GNL) -c $< -o $@

clean:	
			@echo "$(VIOLET)######## Supressing files and library ######## $(YELLOW)"
			make fclean -C $(PRINTF)
			make fclean -C $(GNL)
			@rm -rf $(OBJS_PATH)
			@rm -rf $(OBJB_PATH)


fclean:		clean
			@rm -rf libgnl.a
			@rm -rf libftprintf.a
			@rm -rf $(NAME)
			@rm -rf $(NAME_BONUS)

re:			fclean all

.PHONY:		clean, fclean, re, printf, tmp, bonus, tmp_bonus, all, gnl 
