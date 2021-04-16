/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:41:18 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/15 18:43:21 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		err_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

void	print_stack(t_twostack *set)		// to delete
{
	int	i = 0;
	int stop = (set->a.len > set->b.len) ? set->a.len : set->b.len;

	printf("stop = %d\n", stop);
	printf("stack A {%d}\t\tstack B {%d}\n\n", set->a.len, set->b.len);
	while (i < stop)
	{
		if (set->a.len > i)
			printf("%-11d", set->a.content[i]);
		else
			printf("-----------");
		printf("\t\t");
		if (set->b.len > i)
			printf("%-11d\n", set->b.content[i]);
		else
			printf("-----------\n");
		i++;
	}
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

int		initargs(int ac, char **av, t_twostack *set)
{
	int		i;

	if (!(set->a.content = malloc(sizeof(int) * ac - 1)))
		return (-1);
	if (!(set->b.content = malloc(sizeof(int) * ac - 1)))
		return (-1);
	i = 0;
	while (i < (ac - 1))
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

int		start_check(int ac, char **av, t_twostack *set)
{
	char	*line;

	if (initargs(ac, av, set) == -1)
		return (err_msg());
	//print_stack(set);
	while (get_next_line(0, &line) > 0)
	{
		if (disp_cmd(line, set) == -1)
			return (err_msg());
		//print_stack(set);
	}
	if (set->b.len != 0 || sort_a(set) != 1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	return (0);
}
