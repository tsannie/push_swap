/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:39:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/12 17:35:03 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_a(t_twostack *set)
{
	int	tmp;

	if (set->a.len >= 2)
	{
		tmp = set->a.content[0];
		set->a.content[0]= set->a.content[1];
		set->a.content[1] = tmp;
	}
}

void	swap_b(t_twostack *set)
{
	int	tmp;

	if (set->b.len >= 2)
	{
		tmp = set->b.content[0];
		set->b.content[0]= set->b.content[1];
		set->b.content[1] = tmp;
	}
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
