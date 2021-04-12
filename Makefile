# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 16:22:17 by tsannie           #+#    #+#              #
#    Updated: 2021/04/12 12:37:05 by tsannie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
			@$(MAKE) -C ./checker_srcs
			@cp ./checker_srcs/checker ./

clean:
			@$(MAKE) clean -C ./checker_srcs

fclean:
			@$(MAKE) fclean -C ./checker_srcs
			@touch checker
			@rm checker

re:			fclean all
