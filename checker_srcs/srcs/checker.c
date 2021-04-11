/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:39:52 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/09 01:44:27 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	init_struct(t_twostack *set)
{
	set->a.content = NULL;
	set->b.content = NULL;
}

int		main(int ac, char **av)
{
	t_twostack		*set;

	if (ac == 1)
		return (0);
	if (!(set = malloc(sizeof(t_twostack) * 1)))
		return (-1);
	init_struct(set);
	start_check(ac, av, set);
	return (0);
}
