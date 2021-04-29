/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:30:12 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/28 13:18:59 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void		free_all(t_twostack *set, t_search *param)
{
	free(set->a.content);
	free(set->b.content);
	free(set);
	free(param);
}

int				main(int ac, char **av)
{
	t_twostack		*set;
	t_search		*param;

	if (ac == 1)
		return (0);
	if (!(set = malloc(sizeof(t_twostack) * 1)))
		return (-1);
	if (!(param = malloc(sizeof(t_search) * 1)))
		return (-1);
	init_struct(set);
	if (initargs(ac, av, 1, set) == -1)
	{
		free_all(set, param);
		return (err_msg());
	}
	switch_algo(set, param);
	free_all(set, param);
	return (0);
}
