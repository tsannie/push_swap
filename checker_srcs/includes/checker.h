/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:30 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/09 16:39:55 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

# include <stdio.h>

typedef struct	s_stack
{
	int			*content;
	int			len;
}				t_stack;

typedef struct	s_twostack
{
	t_stack		a;
	t_stack		b;
}				t_twostack;

int		start_check(int ac, char **av, t_twostack *set);

#endif
