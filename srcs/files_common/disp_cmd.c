/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:39:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/26 11:33:00 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	init_struct(t_twostack *set)
{
	set->a.content = NULL;
	set->b.content = NULL;
	set->a.len = 0;
	set->b.len = 0;
	set->opt = 0;
}

int		disp_next(char *line, t_twostack *set)
{
	if (ft_streql(line, "ra") == 1)
		rotate_a(set);
	else if (ft_streql(line, "rb") == 1)
		rotate_b(set);
	else if (ft_streql(line, "rr") == 1)
	{
		rotate_a(set);
		rotate_b(set);
	}
	else if (ft_streql(line, "rra") == 1)
		rev_rotate_a(set);
	else if (ft_streql(line, "rrb") == 1)
		rev_rotate_b(set);
	else if (ft_streql(line, "rrr") == 1)
	{
		rev_rotate_a(set);
		rev_rotate_b(set);
	}
	else
		return (-1);
	return (0);
}

int		disp_cmd(char *line, t_twostack *set)
{
	if (ft_streql(line, "sa") == 1)
		swap_a(set);
	else if (ft_streql(line, "sb") == 1)
		swap_b(set);
	else if (ft_streql(line, "ss") == 1)
	{
		swap_a(set);
		swap_b(set);
	}
	else if (ft_streql(line, "pa") == 1)
		push_a(set);
	else if (ft_streql(line, "pb") == 1)
		push_b(set);
	else
		return (disp_next(line, set));
	return (0);
}
