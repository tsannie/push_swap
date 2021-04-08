# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 16:22:17 by tsannie           #+#    #+#              #
#    Updated: 2021/04/08 17:36:54 by tsannie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
			@$(MAKE) -C ./checker
			@cp ./checker/checker ./
			#@$(MAKE) -C ./push_swap
			#@cp ./push_swap/push_swap ./

clean:
			@$(MAKE) clean -C ./checker
			#@$(MAKE) clean -C ./push_swap

fclean:
			@rm checker push_swap
			@make -C checker fclean
			@make -C push_swap fclean

re:			fclean all
