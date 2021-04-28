/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:04:42 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/28 08:57:24 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

int		split_mediane_a(t_twostack *set, t_search *param)
{
	int	mediane;
	int tmp;
	int	i;

	i = 0;
	tmp = set->a.len - param->nb_found;
	mediane = def_mediane(set->a.content, set->a.len - param->nb_found);
	//printf("mediane_a = %d\n", mediane);	// swap is possible ?
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
	int tmp;
	int	i;

	i = 0;
	tmp = set->b.len;
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

int		search_big_small(t_twostack *set, t_search *param, int biggest)
{
	int max;
	int i;

	max = 0;
	while (1)
	{
		i = 0;
		while (i <= max)
		{
			if (set->b.content[i] == biggest
				|| set->b.content[i] == param->smaller)
				return (set->b.content[i]);
			i++;
		}
		i = set->b.len - 1;
		while (i >= (set->b.len - max - 1))
		{
			if (set->b.content[i] == biggest
				|| set->b.content[i] == param->smaller)
				return (set->b.content[i]);
			i--;
		}
		max++;
	}
	return (0);
}

int		up_or_down(t_twostack *set, int search)
{
	int	i;
	int	rb;
	int rrb;

	rb = 0;
	i = 0;
	while (set->b.content[i] != search)
	{
		rb++;
		i++;
	}
	i = set->b.len - 1;
	rrb = 0;
	while (set->b.content[i] != search)
	{
		rrb++;
		i--;
	}
	return ((rrb > rb) ? 1 : 2);
}

void	moove_up_down_b(t_twostack *set, t_search *param, int search)
{
	int up_down;

	up_down = up_or_down(set, search);
	while (set->b.content[0] != search)
	{
		if (set->b.content[0] == param->smaller)
			found_smaller_b(set, param);
		else if (up_down == 1)
		{
			ft_putstr_fd("rb\n", 1);
			rotate_b(set);
		}
		else
		{
			ft_putstr_fd("rrb\n", 1);
			rev_rotate_b(set);
		}
	}
	if (set->b.content[0] == param->smaller)
		found_smaller_b(set, param);
	else
	{
		ft_putstr_fd("pa\n", 1);
		push_a(set);
	}
}

void	sort_b_fast(t_twostack *set, t_search *param)
{
	int last_push;
	int biggest_qone;

	while (set->b.len != 0)
	{
		biggest_qone = max_stack(set->b.content, set->b.len);
		last_push = search_big_small(set, param, biggest_qone);
		moove_up_down_b(set, param, last_push);
	}
	while (set->a.content[0] == param->smaller)
		found_smaller_a(set, param);
}

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
