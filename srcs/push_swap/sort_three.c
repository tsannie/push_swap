/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:06:31 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/28 08:28:36 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	little_two(t_twostack *set)
{
	if (set->a.content[0] > set->a.content[1])
	{
		ft_putstr_fd("sa\n", 1);
		swap_a(set);
	}
}

void	little_three(t_twostack *set)
{
	if ((set->a.len) == 2)
		little_two(set);
	else if ((set->a.len) == 3)
	{
		little_two(set);
		if (sort_a(set) != 1)
		{
			ft_putstr_fd("rra\n", 1);
			rev_rotate_a(set);
		}
		little_two(set);
	}
}
