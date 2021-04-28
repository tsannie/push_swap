/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:30:12 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/28 08:58:37 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int				main(int ac, char **av)
{
	t_twostack		*set;
	t_search		*param;


	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = split_arg(av[1], ' ');
		ac = nb_nb(av);
	}
	if (!(set = malloc(sizeof(t_twostack) * 1)))
		return (-1);
	if (!(param = malloc(sizeof(t_search) * 1)))
		return (-1);
	init_struct(set);
	if (initargs(ac, av, 1, set) == -1)
		return (err_msg());		// free
	switch_algo(set, param);
	//free_all(set);
	return (0);
}
