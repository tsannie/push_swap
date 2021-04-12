/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:39:52 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/12 13:36:07 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_args(char **str)		// to delete
{
	int		i;

	i = 0;
	if (!str[0])
	{
		printf("NO ARGS\n");
	}
	else
	{
		printf("args_stock : \n");
		while (str[i])
		{
			printf("- Argument %d\t:\t|%s|\n", i, str[i]);
			i++;
		}
	}
}

static	int		nb_nb(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static	void	init_struct(t_twostack *set)
{
	set->a.content = NULL;
	set->b.content = NULL;
	set->a.len = 0;
	set->b.len = 0;
}

int		main(int ac, char **av)
{
	t_twostack		*set;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = split_arg(av[1], ' ');		// for ARG=`ruby -e "puts (1..50).to_a.shuffle.join('|')"`
		ac = nb_nb(av);
	}
	//print_args(av);
	if (!(set = malloc(sizeof(t_twostack) * 1)))
		return (-1);
	init_struct(set);
	if (start_check(ac, av, set) == -1)
		return (-1);
	return (0);
}
