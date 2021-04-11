/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:41:18 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/09 16:59:01 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		initargs(int ac, char **av, t_twostack *set)
{
	int		i;

	set->a.len = ac - 1;
	i = 1;
	while (i < set->a.len)
	{
		printf("BYE\n");
		//if (ft_isnumber(av[i]) == 0)
			set->a.content[i - 1] = ft_atoi(av[i]);
		i++;
	}
	i = 0;
	while (i < set->a.len)
	{
		printf("%d \n", set->a.content[i]);
		i++;
	}
	return (0);
}

int		start_check(int ac, char **av, t_twostack *set)
{
	char	*line;

	initargs(ac, av, set);
	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
	}
	printf("bye\n");
	return (0);
}
