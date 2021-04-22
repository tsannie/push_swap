/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:26:53 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/22 15:49:42 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_logic(t_twostack *set)
{
	if (set->b.content[0] < set->b.content[1] && set->a.content[0] > set->a.content[1])
	{
		ft_putstr_fd("ss\n", 1);
		swap_a(set);
		swap_b(set);
	}
	else if (set->a.content[0] > set->a.content[1])
	{
		ft_putstr_fd("sa\n", 1);
		swap_a(set);
	}
	else if (set->b.content[0] < set->b.content[1])
	{
		ft_putstr_fd("sb\n", 1);
		swap_b(set);
	}
}

void	sort_stack_a(t_twostack *set)
{
	if ((set->a.len) == 2)
		swap_logic(set);
	else if ((set->a.len) == 3)
	{
		swap_logic(set);
		if (sort_a(set) != 1)
		{
			ft_putstr_fd("rra\n", 1);
			rev_rotate_a(set);
		}
		swap_logic(set);
	}
}

void	little_five(t_twostack *set, t_search *param)
{
	split_mediane_a(set, param);
	sort_stack_a(set);
	ft_putstr_fd("pa\npa\n", 1);
	push_a(set);
	push_a(set);
	//print_stack(set);
}
