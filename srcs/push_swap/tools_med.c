/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_med.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:34:57 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/30 10:46:07 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	push_after_mediane(t_twostack *set, t_search *param, int mediane)
{
	while (set->a.content[0] <= mediane)
	{
		if (set->a.content[0] == param->smaller)
			found_smaller_a(set, param);
		else
		{
			push_b(set);
			ft_putstr_fd("pb\n", 1);
		}
	}
	sort_b_fast(set, param);
}

int		strat2_split_a(t_twostack *set, int mediane, int max)
{
	int cpt;

	cpt = 0;
	while (set->a.content[0] < max)
	{
		if (set->a.content[0] >= mediane)
		{
			rotate_a(set);
			ft_putstr_fd("ra\n", 1);
			cpt++;
		}
		else
		{
			push_b(set);
			ft_putstr_fd("pb\n", 1);
		}
	}
	return (cpt);
}

int		end_split(int *tab, int len, int mediane)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tab[i] < mediane)
			return (1);
		i++;
	}
	return (0);
}

int		split_mediane_a(t_twostack *set, t_search *param)
{
	int	mediane;
	int tmp;
	int	i;

	i = 0;
	tmp = set->a.len - param->nb_found;
	mediane = def_mediane(set->a.content, set->a.len - param->nb_found);
	while (i < tmp && end_split(set->a.content, tmp, mediane) == 1)
	{
		if (set->a.content[0] < mediane)
		{
			push_b(set);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			rotate_a(set);
			ft_putstr_fd("ra\n", 1);
		}
		i++;
	}
	return (mediane);
}

int		split_mediane_b(t_twostack *set, t_search *param)
{
	int	mediane;
	int	i;

	i = 0;
	mediane = def_mediane(set->b.content, set->b.len);
	while (max_stack(set->b.content, set->b.len) > mediane && set->b.len > 0)
	{
		if (set->b.content[0] == param->smaller)
			found_smaller_b(set, param);
		else if (set->b.content[0] >= mediane)
		{
			ft_putstr_fd("pa\n", 1);
			push_a(set);
		}
		else
		{
			ft_putstr_fd("rb\n", 1);
			rotate_b(set);
		}
		i++;
	}
	return (mediane);
}
