/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:06:35 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/22 14:54:10 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	init_param(t_twostack *set, t_search *param)
{
	param->nb_found = 0;
	param->smaller = min_stack(set->a.content, set->a.len);
}

void	switch_algo(t_twostack *set, t_search *param)
{
	init_param(set, param);
	if (set->a.len <= 3)
		little_three(set, param);
	else if (set->a.len <= 5)
		little_five(set, param);
	else
		algo_sort(set, param);
	//print_stack(set);
}
