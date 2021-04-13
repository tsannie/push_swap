/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:04:42 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/13 16:56:10 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	next_val(t_twostack *set, t_search *param)
{
	int		i;
	int		len_a;


	len_a = set->a.len - param->nb_found;
	print_stack(set);
	printf("len_a = %d\nset->a.len = %d\nparam->nb_found = %d\n", len_a, set->a.len, param->nb_found);
	i = 0;
	param->is_search = (len_a > 0) ? set->a.content[i] : set->b.content[i];
	while (i < len_a)
	{
		if (set->a.content[i] < param->is_search)
			param->is_search = set->a.content[i];
		i++;
	}

	i = 0;
	while (i < set->b.len)
	{
		if (set->b.content[i] < param->is_search)
			param->is_search = set->b.content[i];
		i++;
	}
}

int		next_val_stack(int *tab, int len, int val)
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
		ret = next_val_stack(set->a.content, len, ret);
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
		ret = next_val_stack(set->b.content, len, ret);
		e++;
	}
	return (ret);
}

void	foundin_a(t_twostack *set, t_search *param)
{
	param->nb_found++;
	rotate_a(set);
	printf("\n\n\n{%d} is found\n", param->is_search);
	next_val(set, param);
	printf("{%d} is search\n\n\n", param->is_search);
}

void	foundin_b(t_twostack *set, t_search *param)
{
	param->nb_found++;
	push_a(set);
	rotate_a(set);
	printf("\n\n\n{%d} is found\n", param->is_search);
	next_val(set, param);
	printf("{%d} is search\n\n\n", param->is_search);
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
		if (set->a.content[0] == param->is_search)
			foundin_a(set, param);
		else
			push_b(set);
		i++;
	}
}

int		split_mediane_a(t_twostack *set, t_search *param)
{
	int	mediane;
	int tmp;
	int	i;

	if (set->a.len < 3)
		return (-1);
	i = 0;
	tmp = set->a.len - param->nb_found;
	mediane = def_mediane_a(set, param);
	printf("mediane_a = %d\n", mediane);	// swap is possible ?
	while (i < tmp)
	{
		//if (set->a.content[0] == param->is_search)
		//	foundin_a(set, param);
		if (set->a.content[0] < mediane)
			push_b(set);
		else
			rotate_a(set);
		i++;
	}
	return (0);
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
	printf("mediane_b = %d\n", mediane);
	while (i < tmp)
	{
		if (set->b.content[0] == param->is_search)
			foundin_b(set, param);
		else if (set->b.content[0] > mediane)
			push_a(set);
		else
			rotate_b(set);
		i++;
	}
	print_stack(set);
	return (0);
}

void	init_param(t_twostack *set, t_search *param)
{
	param->nb_found = 0;
	param->is_search = min_stack(set->a.content, set->a.len);
}

void	little_two(t_twostack *set, t_search *param)
{
	while (set->b.len != 0)
	{
		if (set->b.content[0] == param->is_search)
		{
			printf("ENTER HERE\n");
			foundin_b(set, param);
		}
		else
			swap_b(set);		// faut verif swap a pour ss
		//print_stack(set);
	}
}

void	little_one(t_twostack *set, t_search *param)
{
	if (set->b.content[0] == param->is_search)
		foundin_b(set, param);
	else
	{
		push_a(set);
		printf("CE CAS N'EST VRAIMENT PAS LOGIQUE\n.");
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
		if (set->b.content[2] == param->is_search)
		{
			rev_rotate_b(set);
			foundin_b(set, param);
		}
		else
		{
			little_two(set, param);
		}
	}


}

void	algo_sort(t_twostack *set, t_search *param)
{
	init_param(set, param);
	print_stack(set);
	printf("\n-----------------------------------------------\nPART 1 (mediane a):\n\n");
	split_mediane_a(set, param);
	while (set->b.len != 0 || sort_a(set) != 1)
	{
		print_stack(set);
		printf("\n-----------------------------------------------\nPART 2 (mediane b):\n\n");
		while (split_mediane_b(set, param) != -1)	// affichage a l'interieur
		{}		// transfert medianne avec ?

		printf("\n-----------------------------------------------\nPART 3 (little three):\n\n");
		little_three(set, param);
		print_stack(set);

		printf("\n-----------------------------------------------\nPART 4 (mediane a p2):\n\n");
		moove_second_mediane_a(set, param);
		print_stack(set);
	}

}
