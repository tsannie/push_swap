/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:39:52 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/13 07:57:17 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_all(t_twostack *set)
{
	free(set->a.content);
	free(set->b.content);
	free(set);
}

int				main(int ac, char **av)
{
	t_twostack		*set;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = split_arg(av[1], ' ');		// for ARG=`ruby -e "puts (1..50).to_a.shuffle.join('|')"`
		ac = nb_nb(av);
	}
	if (!(set = malloc(sizeof(t_twostack) * 1)))
		return (-1);
	init_struct(set);
	if (start_check(ac, av, set) == -1)
	{
		free_all(set);
		return (-1);
	}
	free_all(set);
	return (0);
}
