# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 15:57:25 by tsannie           #+#    #+#              #
#    Updated: 2021/04/27 13:20:55 by tsannie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################
#                            Informations                            #
######################################################################

NAME_C			= checker
NAME			= push_swap

CC				= @gcc
CFLAGS			= -Wall -Wextra -Werror #-fsanitize=leak
LIB_FLAGS		= -lncurses -lft -L ./libft
RM				= @rm -rf
LIBFT			= ./libft
INCLUDE			= -I ./srcs/includes
INCLUDE_LIB		= -I ./libft/libft.a

######################################################################
#                               C0l0r$                               #
######################################################################

BLACK			:= $(shell tput -Txterm setaf 0)
RED				:= $(shell tput -Txterm setaf 1)
GREEN			:= $(shell tput -Txterm setaf 2)
YELLOW			:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE		:= $(shell tput -Txterm setaf 4)
PURPLE			:= $(shell tput -Txterm setaf 5)
BLUE			:= $(shell tput -Txterm setaf 6)
WHITE			:= $(shell tput -Txterm setaf 7)
BOLD			:= $(shell tput -Txterm bold)
END				:= $(shell tput -Txterm sgr0)
NAMEC			= ${BLUE}${BOLD}$(NAME_C)${END}
NAMEP			= ${BLUE}${BOLD}$(NAME)${END}

######################################################################
#                        Source Files Checker                        #
######################################################################

PUSHSWAP		= push_swap_main.c algo_sort.c sort_three.c choose_sort.c \
				sort_five.c

CHECKER			= checker_main.c

COMMON			= start_check.c split_arg.c disp_cmd.c swap_cmd.c \
				push_cmd.c rotate_cmd.c reverse_rotate_cmd.c handling_tab.c \
				print_set.c tools_stack.c


SRC_CHECKER		= $(addprefix srcs/checker/, $(CHECKER)) \
					$(addprefix srcs/files_common/, $(COMMON))

SRC_PUSHSWAP	= $(addprefix srcs/push_swap/, $(PUSHSWAP)) \
					$(addprefix srcs/files_common/, $(COMMON))

######################################################################
#                            Object Files                            #
######################################################################

OBJ_C			= $(SRC_CHECKER:c=o)

OBJ_P			= $(SRC_PUSHSWAP:c=o)

######################################################################
#                               Rules                                #
######################################################################

%.o: %.c
			@printf "${PURPLE}${BOLD}%-35.35s\r${END}" $@
			${CC} ${CFLAGS} -c $< -o $@

all:
			@printf "${PURPLE}${BOLD}Start compile ...\n${END}"
			@$(MAKE) $(NAME)

$(NAME): 	$(OBJ_C) $(OBJ_P)
		@echo "\n"
		@$(MAKE) -C $(LIBFT)
		$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LIB) -o $(NAME_C) $(OBJ_C) $(LIB_FLAGS)
		$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LIB) -o $(NAME) $(OBJ_P) $(LIB_FLAGS)
		@echo "\n$(NAMEC) ${GREEN}has been build !${END}\n"
		@echo "$(NAMEP) ${GREEN}has been build !${END}\n"

test:
		@$(MAKE) all
		@./test.sh
		@$(MAKE) fclean

stats:
		@$(MAKE) all
		@./push_stats.sh
		@$(MAKE) fclean

clean:
		$(RM) $(OBJ_C) $(OBJ_P)
		@$(MAKE) clean -C $(LIBFT)
		@echo "${LIGHTPURPLE}Cleaning ...${END}\n"

fclean:		clean
		$(RM) $(NAME_C) $(NAME)
		@$(MAKE) fclean -C $(LIBFT)
		@echo "${LIGHTPURPLE}Delete $(NAMEC)${LIGHTPURPLE} and" \
		"$(NAMEP)${LIGHTPURPLE} ...${END}\n"

re:			fclean all

.PHONY:		all test clean fclean re
