/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:38:48 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/30 10:45:26 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		count_nbrrr(t_twostack *set, t_search *param)
{
	int		i;
	int		i_max;
	int		max;
	int		cpt;

	i = 0;
	max = set->b.content[0];
	i_max = 0;
	cpt = 0;
	while (cpt < (set->a.len - param->nb_found) && (cpt < set->b.len))
	{
		if (set->b.content[i] > max)
		{
			max = set->b.content[i];
			i_max = cpt;
		}
		i--;
		if (i == -1)
			i = set->b.len - 1;
		cpt++;
	}
	return (i_max);
}

void	go_up(t_twostack *set, int rrr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (i < rrr)
		{
			ft_putstr_fd("rrr\n", 1);
			rev_rotate_a(set);
			rev_rotate_b(set);
		}
		else
		{
			ft_putstr_fd("rra\n", 1);
			rev_rotate_a(set);
		}
		i++;
	}
}

void	next_val_small(t_twostack *set, t_search *param)
{
	int		i;
	int		len_a;

	len_a = set->a.len - param->nb_found;
	i = 0;
	param->smaller = (len_a > 0) ? set->a.content[i] : set->b.content[i];
	while (i < len_a)
	{
		if (set->a.content[i] < param->smaller)
			param->smaller = set->a.content[i];
		i++;
	}
	i = 0;
	while (i < set->b.len)
	{
		if (set->b.content[i] < param->smaller)
			param->smaller = set->b.content[i];
		i++;
	}
}

void	found_smaller_a(t_twostack *set, t_search *param)
{
	param->nb_found++;
	ft_putstr_fd("ra\n", 1);
	rotate_a(set);
	if ((set->a.len - param->nb_found) != 0 || set->b.len != 0)
		next_val_small(set, param);
}

void	found_smaller_b(t_twostack *set, t_search *param)
{
	param->nb_found++;
	ft_putstr_fd("pa\nra\n", 1);
	push_a(set);
	rotate_a(set);
	if ((set->a.len - param->nb_found) != 0 || set->b.len != 0)
		next_val_small(set, param);
}
