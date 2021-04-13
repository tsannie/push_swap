/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:38:49 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/13 07:35:37 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate_a(t_twostack *set)
{
	int	value;

	if (set->a.len >= 2)
	{
		value = replace_up_a(set);
		place_down_a(value, set);
	}
}

void	rotate_b(t_twostack *set)
{
	int	value;

	if (set->b.len >= 2)
	{
		value = replace_up_b(set);
		place_down_b(value, set);
	}
}
