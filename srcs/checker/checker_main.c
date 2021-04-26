/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:39:52 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/26 16:08:37 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_all(t_twostack *set)
{
	free(set->a.content);
	free(set->b.content);
	free(set);
}

static int	opt(char *option, t_twostack *set)
{
	if (ft_streql(option, "-v") == 1)
	{
		if (set->opt < 1)
			set->opt = 1;
	}
	else if (ft_streql(option, "-c") == 1)
	{
		if (set->opt < 2)
			set->opt = 2;
	}
	else
		return (-1);
	return (0);
}

int				main(int ac, char **av)
{
	t_twostack		*set;
	int				arg;

	arg = 1;
	if (ac == arg)
		return (0);
	if (!(set = malloc(sizeof(t_twostack) * 1)))
		return (-1);
	init_struct(set);
	while (av[arg][0] == '-')
	{
		if (opt(av[arg], set) == -1)
		{
			free_all(set);
			return (err_msg());
		}
		arg++;
	}
	if (ac == (arg + 1))
	{
		av = split_arg(av[ac - 1], ' ');		// for ARG=`ruby -e "puts (1..50).to_a.shuffle.join('|')"`
		ac = nb_nb(av);
		arg = 1;
	}
	//printf("opt = %d\narg = %d\nac = %d\n",set->opt, arg, ac);
	if (start_check(ac, av, arg, set) == -1)
	{
		free_all(set);
		return (-1);
	}
	//printf("opt = %d\n",set->opt);
	free_all(set);
	return (0);
}
