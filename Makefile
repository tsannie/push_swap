# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 16:22:17 by tsannie           #+#    #+#              #
#    Updated: 2021/04/09 02:05:12 by tsannie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
			@$(MAKE) -C ./checker_srcs
			@cp ./checker_srcs/checker ./

clean:
			@$(MAKE) clean -C ./checker_srcs

fclean:
			@rm checker
			@$(MAKE) fclean -C ./checker_srcs

re:			fclean all
