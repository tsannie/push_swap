/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:09:23 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/13 07:16:08 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		replace_down_a(t_twostack *set)
{
	set->a.len--;
	return (set->a.content[set->a.len]);
}

int		replace_down_b(t_twostack *set)
{
	set->b.len--;
	return (set->b.content[set->b.len]);
}

void	rev_rotate_a(t_twostack *set)
{
	int	value;

	if (set->a.len >= 2)
	{
		value = replace_down_a(set);
		place_up_a(value, set);
	}
}

void	rev_rotate_b(t_twostack *set)
{
	int	value;

	if (set->b.len >= 2)
	{
		value = replace_down_b(set);
		place_up_b(value, set);
	}
}
