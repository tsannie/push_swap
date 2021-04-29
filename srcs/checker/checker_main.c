/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:39:52 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/28 13:16:34 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void		free_all(t_twostack *set)
{
	free(set->a.content);
	free(set->b.content);
	free(set);
}

static int		opt(char *option, t_twostack *set)
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

int				search_opt(int ac, char **av, int arg, t_twostack *set)
{
	init_struct(set);
	while (av[arg][0] == '-')
	{
		if (opt(av[arg], set) == -1)
		{
			free_all(set);
			return (err_msg());
		}
		arg++;
		if (ac == arg)
			return (0);
	}
	return (arg);
}

int				main(int ac, char **av)
{
	t_twostack		*set;
	int				arg;

	if (!(set = malloc(sizeof(t_twostack) * 1)))
		return (-1);
	arg = 1;
	if ((arg = search_opt(ac, av, arg, set)) <= 0)
	{
		free_all(set);
		return (arg);	
	}
	if (start_check(ac, av, arg, set) == -1)
	{
		free_all(set);
		return (-1);
	}
	//ft_free_dbtab(slt);
	free_all(set);
	return (0);
}
