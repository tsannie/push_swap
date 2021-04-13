/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:29:55 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/13 07:30:55 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_a(t_twostack *set)
{
	int	tmp;

	if (set->a.len >= 2)
	{
		tmp = set->a.content[0];
		set->a.content[0] = set->a.content[1];
		set->a.content[1] = tmp;
	}
}

void	swap_b(t_twostack *set)
{
	int	tmp;

	if (set->b.len >= 2)
	{
		tmp = set->b.content[0];
		set->b.content[0] = set->b.content[1];
		set->b.content[1] = tmp;
	}
}
