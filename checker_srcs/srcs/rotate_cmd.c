/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:38:49 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/12 16:11:38 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	place_down_a(int value, t_twostack *set)
{
	set->a.len++;
	set->a.content[set->a.len - 1] = value;
}

void	place_down_b(int value, t_twostack *set)
{
	set->b.len++;
	set->b.content[set->b.len - 1] = value;
}

void	rotate_a(t_twostack *set)
{
	int	value;;

	if (set->a.len >= 2)
	{
		//printf("\n\n\n------------------------------\n");
		value = replace_up_a(set);
		//print_stack(set);
		place_down_a(value, set);
	}
}

void	rotate_b(t_twostack *set)
{
	int	value;;

	if (set->b.len >= 2)
	{
		//printf("\n\n\n------------------------------\n");
		value = replace_up_b(set);
		//print_stack(set);
		place_down_b(value, set);
	}
}