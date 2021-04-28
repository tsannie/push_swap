/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:41:18 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/28 13:19:51 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		err_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

int		not_stock(t_twostack *set, char *str)
{
	int		value;
	int		i;

	i = 0;
	value = ft_atoi(str);
	while (i < set->a.len)
	{
		if (set->a.content[i] == value)
			return (-1);
		i++;
	}
	return (0);
}

int		initargs(int ac, char **av, int arg, t_twostack *set)
{
	int		i;
	int		e;

	if (!(set->a.content = malloc(sizeof(int) * (ac - arg))))
		return (-1);
	if (!(set->b.content = malloc(sizeof(int) * (ac - arg))))
		return (-1);
	i = arg;
	e = 0;
	while (i < ac)
	{
		if (ft_isnumber(av[i]) == 1 && not_stock(set, av[i]) == 0)
		{
			set->a.content[e] = ft_atoi(av[i]);
			set->a.len++;
			e++;
		}
		else
			return (-1);
		i++;
	}
	return (0);
}

int		sort_a(t_twostack *set)
{
	int	i;

	i = 0;
	while (i < set->a.len - 1)
	{
		if (set->a.content[i] > set->a.content[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		start_check(int ac, char **av, int arg, t_twostack *set)
{
	char	*line;

	if (initargs(ac, av, arg, set) == -1)
		return (err_msg());
	while (get_next_line(0, &line) > 0)
	{
		if (disp_cmd(line, set) == -1)
			return (err_msg());
		if (set->opt > 0)
			print_stack(set, line);
		free(line);
	}
	if (set->b.len != 0 || sort_a(set) != 1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	return (0);
}
