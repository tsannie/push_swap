/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:30 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/12 16:23:11 by tsannie          ###   ########.fr       */
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
int		disp_cmd(char *line, t_twostack *set);
void	push_a(t_twostack *set);
void	push_b(t_twostack *set);
int		replace_up_a(t_twostack *set);
int		replace_up_b(t_twostack *set);
void	place_up_a(int value, t_twostack *set);
void	place_up_b(int value, t_twostack *set);
void	rotate_a(t_twostack *set);
void	rotate_b(t_twostack *set);
void	rev_rotate_a(t_twostack *set);
void	rev_rotate_b(t_twostack *set);

void	print_args(char **str);		// to delete
void	print_stack(t_twostack *set);		// to delete
char	**split_arg(const char *str, char charset);

#endif
