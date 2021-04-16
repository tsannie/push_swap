/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:04:42 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/16 15:33:14 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	next_val_small(t_twostack *set, t_search *param)
{
	int		i;
	int		len_a;


	len_a = set->a.len - param->nb_found;
	//print_stack(set);
	//printf("len_a = %d\nset->a.len = %d\nparam->nb_found = %d\n", len_a, set->a.len, param->nb_found);
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

void	next_val_bigger(t_twostack *set, t_search *param)
{
	int		i;
	int		len_a;


	len_a = set->a.len - param->nb_found;
	//print_stack(set);
	//printf("len_a = %d\nset->a.len = %d\nparam->nb_found = %d\n", len_a, set->a.len, param->nb_found);
	i = 0;
	param->bigger = (len_a > 0) ? set->a.content[i] : set->b.content[i];
	while (i < len_a)
	{
		if (set->a.content[i] > param->bigger)
			param->bigger = set->a.content[i];
		i++;
	}

	i = 0;
	while (i < set->b.len)
	{
		if (set->b.content[i] > param->bigger)
			param->bigger = set->b.content[i];
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

void	stock_med(int mediane, t_search *param)
{
	int		*res;
	int		i;

	param->len_med++;
	if (!(res = malloc(sizeof(int) * param->len_med)))
		return ;
	i = 0;
	while (i < param->len_med - 1)
	{
		res[i] = param->stock_med[i];
		i++;
	}
	res[i] = mediane;
	free(param->stock_med);
	param->stock_med = res;
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
	//printf("\n\n\nsmall {%d} is found\n", param->smaller);
	if ((set->a.len - param->nb_found) == 0 && set->b.len == 0)
		param->end = 1;
	else
		next_val_small(set, param);
//	printf("small {%d} is search\n\n\n", param->smaller);
}

void	found_smaller_b(t_twostack *set, t_search *param)
{
	param->nb_found++;
	ft_putstr_fd("pa\nra\n", 1);
	push_a(set);
	rotate_a(set);
	//printf("\n\n\nsmall {%d} is found\n", param->smaller);
	if ((set->a.len - param->nb_found) == 0 && set->b.len == 0)
		param->end = 1;
	else
		next_val_small(set, param);
	//printf("small {%d} is search\n\n\n", param->smaller);
}

void	found_bigger_b(t_twostack *set, t_search *param)
{
	param->nb_found++;
	ft_putstr_fd("pa\n", 1);
	push_a(set);
	//printf("\n\n\nbig {%d} is found\n", param->bigger);
	next_val_bigger(set, param);
	//printf("big {%d} is search\n\n\n", param->bigger);
}

void	moove_second_mediane_a(t_twostack *set, t_search *param)
{
	int tmp;
	int	i;

	i = 0;
	tmp = set->a.len - param->nb_found;
	while (i < tmp)
	{
		// TODO verif si on peut swap pour push direct
		if (set->a.content[0] == param->smaller)
			found_smaller_a(set, param);
		else
		{
			ft_putstr_fd("pb\n", 1);
			push_b(set);
		}
		i++;
	}
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

	if (set->a.len < 3)
		return (-1);		// big three for stack a ?
	i = 0;
	tmp = set->a.len - param->nb_found;
	mediane = def_mediane_a(set, param);
	//printf("mediane_a = %d\n", mediane);	// swap is possible ?
	while (i < tmp) // TO USE REALLY (permet de stop si ca ne set plus) (i < tmp && end_split(set->a.content, tmp, mediane) == 1)
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

	if (set->b.len < 4)
		return (-1);
	i = 0;
	tmp = set->b.len;
	mediane = def_mediane_b(set, param);
	//printf("mediane_b = %d\n", mediane);
	while (i < tmp)
	{
		if (set->b.content[0] == param->bigger)
			found_bigger_b(set, param);
		else if (set->b.content[0] == param->smaller)
			found_smaller_b(set, param);
		else if (set->b.content[0] > mediane)
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
	//print_stack(set);
	return (0);
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

void	init_param(t_twostack *set, t_search *param)
{
	param->len_med = 0;
	param->end = -1;
	param->nb_found = 0;
	param->bigger = max_stack(set->a.content, set->a.len);
	//printf("bigger = %d\n", param->bigger);
	param->smaller = min_stack(set->a.content, set->a.len);
	if (!(param->stock_med = malloc(sizeof(int) * 1)))
		return ;
	param->stock_med[0] = 42;
}

void	little_two(t_twostack *set, t_search *param)
{
	while (set->b.len != 0)
	{
		if (set->b.content[0] == param->smaller)
		{
			//printf("ENTER HERE\n");
			found_smaller_b(set, param);
		}
		else
		{
			ft_putstr_fd("sb\n", 1);
			swap_b(set);		// faut verif swap a pour ss
		}
		//print_stack(set);
	}
}

void	little_one(t_twostack *set, t_search *param)
{
	if (set->b.content[0] == param->smaller)
		found_smaller_b(set, param);
	else
	{
		ft_putstr_fd("pa\n", 1);
		push_a(set);
		//printf("CE CAS N'EST VRAIMENT PAS LOGIQUE\n.");
	}
}

void	little_three(t_twostack *set, t_search *param)
{
	if (set->b.len == 1)
		little_one(set, param);
	else if (set->b.len == 2)
		little_two(set, param);
	else if (set->b.len == 3)
	{
		if (set->b.content[2] == param->smaller)
		{
			ft_putstr_fd("rrb\n", 1);
			rev_rotate_b(set);
			found_smaller_b(set, param);
		}
		else
		{
			little_two(set, param);
		}
	}
}

int		search_push(t_twostack *set, t_search *param, int med)
{
	int	i;
	int	max;
	int	ret;

	ret = set->b.content[0];
	max = 0;
	//printf("med = %d\n\n", med);
	while (1)
	{
		i = 0;
		while (i <= max)
		{
			if (set->b.content[i] > ret)
				ret = set->b.content[i];
			i++;
		}
		i = set->b.len - 1;
		//printf("i = %d\n\n", set->b.content[i]);
		while (i >= (set->b.len - max - 1))
		{
			if (set->b.content[i] > ret)
				ret = set->b.content[i];
			i--;
		}
		//printf("ret = %d\n\n", ret);
		if (ret < med)
			max++;
		else
			return (ret);
	}
	return (0);
}

void	part_one_regroup(t_twostack *set, t_search *param)
{
	int len;
	int last_push;
	int	mediane;
	int	nb_push;

	len = (set->b.len / 2) + 1;
	nb_push = 0;
	while (set->b.len > 5)
	{
		mediane = def_mediane_b(set, param);
		stock_med(mediane, param);
		//printf("mediane = %d\n", mediane);
		//print_stack(set);
		while (max_stack(set->b.content, set->b.len) > mediane)
		{
			last_push = search_push(set, param, mediane);
			//printf("\nlast_push = %d\nnb_push = %d\n len = %d\n", last_push, nb_push, len);
			moove_up_down_b(set, param, last_push);
			nb_push++;
			//print_stack(set);
		}
	}
	sort_b_fast(set, param);
	//print_stack(set);
}

void	push_before_mediane(t_twostack *set, t_search *param)
{
	int	i;
	int mediane;

	i = 0;
	//printf("mediane_a = %d\n", mediane);	// swap is possible ?
	while (i < param->len_med)
	{
		mediane = param->stock_med[i];
		while (set->a.content[0] < mediane)
		{
			if (set->a.content[0] == param->smaller)
				found_smaller_a(set, param);
			else
			{
				//printf("m = %d\n", mediane);
				push_b(set);
				ft_putstr_fd("pb\n", 1);
				//print_stack(set);
			}
		}
		sort_b_fast(set, param);
		i++;
	}
}

void	algo_sort(t_twostack *set, t_search *param)
{
	init_param(set, param);
	//print_stack(set);
	//printf("\n-----------------------------------------------\nPART 1 (mediane a):\n\n");

	stock_med(split_mediane_a(set, param), param);

	//print_stack(set);

	//printf("\n-----------------------------------------------\nPART 2 (regroup):\n\n");

	//while (med_is_classed(set, param, mediane) == 0)
	//{
	part_one_regroup(set, param);
	//print_stack(set);
	//return ;
	//printf("\n-----------------------------------------------\nPART 3 (little sort):\n\n");
	//print_stack(set);
	//moove_second_mediane_a(set, param);
	//print_stack(set);
	//printf("\n-----------------------------------------------\nPART 4 (push q2)):\n\n");
	//return ;
	push_before_mediane(set, param);
	//print_stack(set);
	return ;
	//print_stack(set);

	//sort_b_fast(set, param);
	//print_stack(set);
	//printf("\n-----------------------------------------------\nPART 5 (push after mediane)):\n\n");
	moove_second_mediane_a(set, param);
	//print_stack(set);
	//printf("\n-----------------------------------------------\nPART 6 (sort end)):\n\n");
	sort_b_fast(set, param);
	//print_stack(set);
	//push_before_mediane(set, param, mediane);
	//}
}
