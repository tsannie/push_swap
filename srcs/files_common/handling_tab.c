/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:34:33 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/28 09:09:53 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	place_up_b(int value, t_twostack *set)
{
	int	i;

	set->b.len++;
	i = set->b.len;
	while (i >= 1)
	{
		set->b.content[i] = set->b.content[i - 1];
		i--;
	}
	set->b.content[0] = value;
}

void	place_up_a(int value, t_twostack *set)
{
	int	i;

	set->a.len++;
	i = set->a.len;
	while (i >= 1)
	{
		set->a.content[i] = set->a.content[i - 1];
		i--;
	}
	set->a.content[0] = value;
}

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
