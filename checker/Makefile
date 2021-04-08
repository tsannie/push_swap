# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 15:57:25 by tsannie           #+#    #+#              #
#    Updated: 2021/04/08 17:35:26 by tsannie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################
#                            Informations                            #
######################################################################

NAME			= checker
CC				= @gcc
CFLAGS			= -Wall -Wextra -Werror #-fsanitize=leak
LIB_FLAGS		= -lncurses -lft -Llibft
RM				= @rm -rf
LIBFT			= ./libft
INCLUDE		= -I ./includes
INCLUDE_LIB		= -I ../libft/libft.a

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
NAMEC			= ${BLUE}${BOLD}$(NAME)${END}

######################################################################
#                        Source Files Checker                        #
######################################################################

CHECKER			= checker.c

SRC_CHECKER		= $(addprefix minishell_basic/srcs/bin/, $(CHECKER))

######################################################################
#                            Object Files                            #
######################################################################

OBJ				= $(SRC_CHECKER:c=o)

######################################################################
#                               Rules                                #
######################################################################

%.o: %.c
			@printf "${PURPLE}${BOLD}Start compile ... %-50.50s\r${END}" $@
			${CC} ${CFLAGS} -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJ)
			@echo "\n"
			@$(MAKE) -C $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LIB) -o $(NAME) $(OBJ) $(LIB_FLAGS)
			@echo "\n${GREEN}The $(NAMEC) ${GREEN}has been build !${END}\n"

clean:
			$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) clean -C $(LIBFT)
			@echo "${LIGHTPURPLE}Cleaning ...${END}\n"

fclean:		clean
			$(RM) $(NAME)
			@$(MAKE) fclean -C $(LIBFT)
			@echo "${LIGHTPURPLE}Delete $(NAMEC)${LIGHTPURPLE}...${END}\n"

re:			fclean all

.PHONY:		all test clean fclean re