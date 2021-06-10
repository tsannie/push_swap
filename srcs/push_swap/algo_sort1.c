/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:04:42 by tsannie           #+#    #+#             */
/*   Updated: 2021/06/07 07:31:43 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	part_one_regroup(t_twostack *set, t_search *param)
{
	int	mediane_tmp;
	int	middle;
	int	rrr;
	int cpt;

	middle = split_mediane_a(set, param);
	mediane_tmp = split_mediane_b(set, param);
	split_mediane_b(set, param);
	sort_b_fast(set, param);
	push_after_mediane(set, param, mediane_tmp);
	mediane_tmp = def_mediane(set->a.content,
		set->a.len - param->nb_found - (set->a.len / 2));
	cpt = strat2_split_a(set, mediane_tmp, middle);
	rrr = count_nbrrr(set, param);
	go_up(set, rrr, cpt);
	sort_b_fast(set, param);
	push_after_mediane(set, param, middle);
}

void	second_part_med(t_twostack *set, t_search *param)
{
	int	mediane;
	int rrr;
	int cpt;

	cpt = 0;
	mediane = def_mediane(set->a.content, set->a.len - param->nb_found);
	while (set->a.content[0] != min_stack(set->a.content, set->a.len))
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
	rrr = count_nbrrr(set, param);
	go_up(set, rrr, cpt);
	split_mediane_b(set, param);
	sort_b_fast(set, param);
	push_after_mediane(set, param, mediane);
}

void	end_push(t_twostack *set, t_search *param)
{
	int min;
	int max;

	min = min_stack(set->a.content, set->a.len - param->nb_found);
	max = max_stack(set->a.content, set->a.len - param->nb_found);
	while (set->a.content[0] <= max && set->a.content[0] >= min)
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

void	algo_sort(t_twostack *set, t_search *param)
{
	part_one_regroup(set, param);


	while ((set->a.len - param->nb_found) > 20)
		second_part_med(set, param);
	end_push(set, param);
}
