/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_fast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:41:32 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/30 10:43:05 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		search_big_small(t_twostack *set, t_search *param, int biggest)
{
	int max;
	int i;

	max = 0;
	while (1)
	{
		i = 0;
		while (i <= max)
		{
			if (set->b.content[i] == biggest
				|| set->b.content[i] == param->smaller)
				return (set->b.content[i]);
			i++;
		}
		i = set->b.len - 1;
		while (i >= (set->b.len - max - 1))
		{
			if (set->b.content[i] == biggest
				|| set->b.content[i] == param->smaller)
				return (set->b.content[i]);
			i--;
		}
		max++;
	}
	return (0);
}

int		up_or_down(t_twostack *set, int search)
{
	int	i;
	int	rb;
	int rrb;

	rb = 0;
	i = 0;
	while (set->b.content[i] != search)
	{
		rb++;
		i++;
	}
	i = set->b.len - 1;
	rrb = 0;
	while (set->b.content[i] != search)
	{
		rrb++;
		i--;
	}
	return ((rrb > rb) ? 1 : 2);
}

void	moove_up_down_b(t_twostack *set, t_search *param, int search)
{
	int up_down;

	up_down = up_or_down(set, search);
	while (set->b.content[0] != search)
	{
		if (set->b.content[0] == param->smaller)
			found_smaller_b(set, param);
		else if (up_down == 1)
		{
			ft_putstr_fd("rb\n", 1);
			rotate_b(set);
		}
		else
		{
			ft_putstr_fd("rrb\n", 1);
			rev_rotate_b(set);
		}
	}
	if (set->b.content[0] == param->smaller)
		found_smaller_b(set, param);
	else
	{
		ft_putstr_fd("pa\n", 1);
		push_a(set);
	}
}

void	sort_b_fast(t_twostack *set, t_search *param)
{
	int last_push;
	int biggest_qone;

	while (set->b.len != 0)
	{
		biggest_qone = max_stack(set->b.content, set->b.len);
		last_push = search_big_small(set, param, biggest_qone);
		moove_up_down_b(set, param, last_push);
	}
	while (set->a.content[0] == param->smaller)
		found_smaller_a(set, param);
}
