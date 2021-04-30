/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:37:30 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/30 10:52:07 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_colors.h"
# include "../../libft/libft.h"

typedef struct	s_stack
{
	int			*content;
	int			len;
}				t_stack;

typedef struct	s_twostack
{
	t_stack		a;
	t_stack		b;
	int			opt;
}				t_twostack;

typedef struct	s_search
{
	int			smaller;
	int			nb_found;
}				t_search;

void			print_stack(t_twostack *set, char *cmd);
int				start_check(int ac, char **av, int arg, t_twostack *set);
int				disp_cmd(char *line, t_twostack *set);
void			init_struct(t_twostack *set);
int				err_msg(void);
int				initargs(int ac, char **av, int arg, t_twostack *set);

void			swap_a(t_twostack *set);
void			swap_b(t_twostack *set);
void			push_a(t_twostack *set);
void			push_b(t_twostack *set);
void			rotate_a(t_twostack *set);
void			rotate_b(t_twostack *set);
void			rev_rotate_a(t_twostack *set);
void			rev_rotate_b(t_twostack *set);

int				replace_up_a(t_twostack *set);
int				replace_up_b(t_twostack *set);
void			place_up_a(int value, t_twostack *set);
void			place_up_b(int value, t_twostack *set);
void			place_down_a(int value, t_twostack *set);
void			place_down_b(int value, t_twostack *set);
int				sort_a(t_twostack *set);

int				split_mediane_a(t_twostack *set, t_search *param);
int				split_mediane_b(t_twostack *set, t_search *param);
int				strat2_split_a(t_twostack *set, int mediane, int max);
void			switch_algo(t_twostack *set, t_search *param);
void			algo_sort(t_twostack *set, t_search *param);
void			little_three(t_twostack *set);
void			little_five(t_twostack *set, t_search *param);
void			found_smaller_b(t_twostack *set, t_search *param);
void			found_smaller_a(t_twostack *set, t_search *param);
void			push_after_mediane(t_twostack *set, t_search *param
				, int mediane);
void			sort_b_fast(t_twostack *set, t_search *param);
void			go_up(t_twostack *set, int rrr, int size);
int				count_nbrrr(t_twostack *set, t_search *param);

int				max_stack(int *tab, int len);
int				min_stack(int *tab, int len);
int				def_mediane(int *tab, int len);
int				next_val_bigger(t_twostack *set, int val);

#endif
