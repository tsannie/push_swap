/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:41:18 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/26 18:13:12 by tsannie          ###   ########.fr       */
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

	if (!(set->a.content = malloc(sizeof(int) * (ac - arg))))
		return (-1);
	if (!(set->b.content = malloc(sizeof(int) * (ac - arg))))
		return (-1);
	i = arg - 1;
	while (i < (ac - arg))
	{
		if (ft_isnumber(av[i + 1]) == 1 && not_stock(set, av[i + 1]) == 0)
		{
			set->a.content[i] = ft_atoi(av[i + 1]);
			set->a.len++;
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
//	int		delete = 0;

	if (initargs(ac, av, arg, set) == -1)
		return (err_msg());
	//print_stack(set);
	while (get_next_line(0, &line) > 0)
	{
		if (disp_cmd(line, set) == -1)
			return (err_msg());
		//delete++;
		if (set->opt > 0)
			print_stack(set, line);
		//printf("%d - %s\n\n\n\n", delete, line);
		free(line);
	}
	if (set->b.len != 0 || sort_a(set) != 1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	return (0);
}
