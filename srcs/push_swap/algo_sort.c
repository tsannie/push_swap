/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:04:42 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/22 15:38:12 by tsannie          ###   ########.fr       */
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

int		def_mediane_a(t_twostack *set, t_search *param)
{
	int		e;
	int		ret;
	int		len;

	len = set->a.len - param->nb_found;
	ret = min_stack(set->a.content, len);
	e = 1;
	while (e != ((len) / 2) + 1)
	{
		ret = next_val_small_stack(set->a.content, len, ret);
		e++;
	}
	return (ret);
}

int		def_mediane_b(t_twostack *set, t_search *param)
{
	int		e;
	int		ret;
	int		len;

	len = set->b.len;
	ret = min_stack(set->b.content, len);
	e = 1;
	while (e != ((len) / 2) + 1)
	{
		ret = next_val_small_stack(set->b.content, len, ret);
		e++;
	}
	return (ret);
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

int		strat2_split_a(t_twostack *set, t_search *param, int mediane, int max)
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
	while (i < tmp && end_split(set->a.content, tmp, mediane) == 1) // TO USE REALLY (permet de stop si ca ne set plus) (i < tmp && end_split(set->a.content, tmp, mediane) == 1)
	{
		//if (set->a.content[0] == param->smaller)
		//	found_smaller_a(set, param);
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
	mediane = def_mediane_b(set, param);
	while ((max_stack(set->b.content, set->b.len) > mediane) && set->b.len == 0)
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
	//printf("med = %d\n\n", med);
	while (1)
	{
		i = 0;
		while (i <= max)
		{
			if (set->b.content[i] == biggest || set->b.content[i] == param->smaller)
				return (set->b.content[i]);
			i++;
		}
		i = set->b.len - 1;
		//printf("i = %d\n\n", set->b.content[i]);
		while (i >= (set->b.len - max - 1))
		{
			if (set->b.content[i] == biggest || set->b.content[i] == param->smaller)
				return (set->b.content[i]);
			i--;
		}
		max++;
	}
	return (0);
}

int		up_or_down(t_twostack *set, t_search *param, int search)
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
	//printf("i = %d\n\n", set->b.content[i]);
	rrb = 0;
	while (set->b.content[i] != search)
	{
		rrb++;
		i--;
	}
	//printf("ret = %d\n\n", ret);

	return ((rrb > rb) ? 1 : 2);
}

void	moove_up_down_b(t_twostack *set, t_search *param, int search)
{
	int up_down;

	up_down = up_or_down(set, param, search);
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
	//printf("\n\n-------------------------------------------------------------------\n");
	//printf("push = %d  ||  updown = %d || Before push :\n\n", search, up_down);
	//print_stack(set);
	if (set->b.content[0] == param->smaller)
			found_smaller_b(set, param);
	else
	{
		ft_putstr_fd("pa\n", 1);
		push_a(set);
		//printf("\n\nEntré 2 \n\n");
	}
	//printf("\n\nAfter_push:\n\n");
	//print_stack(set);
}

void	sort_b_fast(t_twostack *set, t_search *param)
{
	int last_push;
	int biggest_qone;

	while (set->b.len != 0)
	{
		biggest_qone = max_stack(set->b.content, set->b.len);
		//printf("biggest_qone = %d\n", biggest_qone);
		last_push = search_big_small(set, param, biggest_qone);
		moove_up_down_b(set, param, last_push);
		//print_stack(set);
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

void	go_up(t_twostack *set, t_search *param, int rrr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (i < rrr)
		{
			ft_putstr_fd("rrr\n" ,1);
			rev_rotate_a(set);
			rev_rotate_b(set);
		}
		else
		{
			ft_putstr_fd("rra\n" ,1);
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
	mediane_tmp = def_mediane(set->a.content, set->a.len - param->nb_found - (set->a.len / 2));
	cpt = strat2_split_a(set, param, mediane_tmp, middle);
	rrr = count_nbrrr(set, param);
	go_up(set, param, rrr, cpt);
	sort_b_fast(set, param);
	push_after_mediane(set, param, middle);

	//print_stack(set);
	//end_part_one(set, param, cpt);
	//print_stack(set);
	//print_stack(set);
}

void	second_part_med(t_twostack *set, t_search *param)
{
	int	mediane;
	int rrr;
	int cpt;

	cpt = 0;
	mediane = def_mediane(set->a.content, set->a.len - param->nb_found);
	//printf("mediane = %d\n", mediane);
	while (set->a.content[0] != min_stack(set->a.content, set->a.len)) // strat2_split_a ?
	{
		if (set->a.content[0] >= mediane)
		{
			rotate_a(set);
			ft_putstr_fd("ra\n", 1);
			cpt++;
		}
		else
		{
			//printf("m = %d\n", mediane);
			push_b(set);
			ft_putstr_fd("pb\n", 1);
			//print_stack(set);
		}
	}
	rrr = count_nbrrr(set, param);
	go_up(set, param, rrr, cpt);
	split_mediane_b(set, param);
	sort_b_fast(set, param);
	push_after_mediane(set, param, mediane);
	//print_stack(set);
	//end_part_one(set, param, cpt);
	//print_stack(set);
	//print_stack(set);
}

void	end_push(t_twostack *set, t_search *param)
{
	int min;
	int max;

	min = min_stack(set->a.content, set->a.len - param->nb_found);
	max = max_stack(set->a.content, set->a.len - param->nb_found);
	while (set->a.content[0] <= max && set->a.content[0] >= min)
	{
		//printf("set->b.content[0] = %d\n", set->b.content[0]);
		if (set->a.content[0] == param->smaller)
			found_smaller_a(set, param);
		else
		{
			push_b(set);
			ft_putstr_fd("pb\n", 1);
		}
		//print_stack(set);
	}
	sort_b_fast(set, param);
}

void	algo_sort(t_twostack *set, t_search *param)
{


	//print_stack(set);
	part_one_regroup(set, param);
	//print_stack(set);
	//print_stack(set);
	while ((set->a.len - param->nb_found) > 20)
		second_part_med(set, param);
	//print_stack(set);
	//push_after_mediane(set, param, max_stack(set->a.content, set->a.len - param->nb_found));
	end_push(set, param);
	//print_stack(set);
}
