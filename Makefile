# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 12:18:20 by mjulliat          #+#    #+#              #
#    Updated: 2022/12/08 21:09:38 by mjulliat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###

CC			= gcc -g
FLAGS		= -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= push_swap
FRAMEWORK	= -framework OpenGL -framework AppKit

	### INCLUDES ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
HEADERS		= incl
PRINTF		= ft_printf

	### SOURCE FILE ###

SOURCES		= main.c\
			  utils.c\
			  utils_2.c\
			  ft1_error.c\
			  ft1_init_env.c\
			  ft1_add_index.c\
			  ft1_split.c\
			  ft1_one_string.c\
			  ft2_solver.c\
			  ft2_swap_and_push.c\
			  ft2_rotate_and_reverse.c

	### OBJETCTS ###

SRCS		= $(addprefix $(SRCS_PATH)/,$(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/,$(SOURCES:.c=.o))

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

$(NAME):	$(OBJ) $(OBJS)
			@echo "$(BLUE)######## Obect file Created ######### $(WHITE)"
			$(CC) $(FLAGS) -L$(PRINTF) -lftprintf $(FRAMEWOKR) -o $@ $^ 
			@echo "$(GREEN)######## Project Compilated ######## $(WHITE)"

printf:
			make -sC $(PRINTF)
			cp ft_printf/libftprintf.a .
			@echo "$(CYAN)######## LIBFTPRINTF.A Created ######## $(WHITE)"

tmp:		
			@mkdir -p objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS) -I$(PRINTF) -c $< -o $@ 

clean:	
			@echo "$(VIOLET)######## Supressing files and library ######## $(YELLOW)"
			make fclean -C $(PRINTF)
			@rm -rf $(OBJS_PATH)


fclean:		clean
			@rm -rf libftprintf.a
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		clean, fclean, re, printf, tmp 
