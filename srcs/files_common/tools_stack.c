/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:45:22 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/26 20:23:29 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		next_val_bigger(t_twostack *set, int val)
{
	int		i;
	int		ret;

	i = 0;
	ret = max_stack(set->a.content, set->a.len);
	while (i < set->a.len)
	{
		if (set->a.content[i] > val && set->a.content[i] < ret)
			ret = set->a.content[i];
		i++;
	}
	i = 0;
	while (i < set->b.content[i])
	{
		if (set->b.content[i] > val && set->b.content[i] < ret)
			ret = set->b.content[i];
		i++;
	}
	return (ret);
}

int		next_val_small_stack(int *tab, int len, int val)
{
	int		i;
	int		ret;

	i = 0;
	ret = val;
	while (i < len && ret == val)
	{
		if (tab[i] > ret)
			ret = tab[i];
		i++;
	}
	if (ret == val)
		return (val);

	i = 0;
	while (i < len)
	{
		if (tab[i] > val && tab[i] < ret)
			ret = tab[i];
		i++;
	}
	return (ret);
}

int		min_stack(int *tab, int len)
{
	int		i;
	int		min;

	i = 0;
	min = tab[0];
	while (i < len)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int		max_stack(int *tab, int len)
{
	int		i;
	int		max;

	i = 0;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int		def_mediane(int *tab, int len)
{
	int		e;
	int		ret;

	if (len <= 0)
		return (0);
	ret = min_stack(tab, len);
	e = 1;
	while (e != ((len) / 2) + 1)
	{
		ret = next_val_small_stack(tab, len, ret);
		e++;
	}
	return (ret);
}
