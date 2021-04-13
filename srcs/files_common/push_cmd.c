/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:48:41 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/13 07:35:10 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		replace_up_b(t_twostack *set)
{
	int ret;
	int	i;

	i = 0;
	ret = set->b.content[0];
	set->b.len--;
	while (i < set->b.len)
	{
		set->b.content[i] = set->b.content[i + 1];
		i++;
	}
	return (ret);
}

int		replace_up_a(t_twostack *set)
{
	int ret;
	int	i;

	i = 0;
	ret = set->a.content[0];
	set->a.len--;
	while (i < set->a.len)
	{
		set->a.content[i] = set->a.content[i + 1];
		i++;
	}
	return (ret);
}

void	push_b(t_twostack *set)
{
	int	value;

	if (set->a.len > 0)
	{
		value = replace_up_a(set);
		place_up_b(value, set);
	}
}

void	push_a(t_twostack *set)
{
	int	value;

	if (set->b.len > 0)
	{
		value = replace_up_b(set);
		place_up_a(value, set);
	}
}
