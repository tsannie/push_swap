/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:48:41 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/12 16:20:01 by tsannie          ###   ########.fr       */
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

void	push_b(t_twostack *set)
{
	int	value;

	//printf("\n\n-------------------------------------\n");
	if (set->a.len > 0)
	{
		value = replace_up_a(set);
		//printf("value = %d\n", value);
		//print_stack(set);
		place_up_b(value, set);
		//print_stack(set);
		//printf("set->b.content[0] = %d | len = %d\n", set->b.content[0], set->b.len);
	}
}

void	push_a(t_twostack *set)
{
	int	value;;

	if (set->b.len > 0)
	{
		value = replace_up_b(set);
		place_up_a(value, set);
	}
}

