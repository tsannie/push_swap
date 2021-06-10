/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:56:29 by tsannie           #+#    #+#             */
/*   Updated: 2021/06/07 07:34:59 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_val(t_stack stack, int i, int clr, int next_place)
{
	int		max;
	int		min;

	max = max_stack(stack.content, stack.len);
	min = min_stack(stack.content, stack.len);
	if (clr == 2 && (stack.content[i] == max || stack.content[i] == min
		|| stack.content[i] == next_place))
	{
		if (stack.content[i] == max)
			printf(""BRED"%-11d"END"", stack.content[i]);
		else if (stack.content[i] == min)
			printf(""BBLUE"%-11d"END"", stack.content[i]);
		else if (stack.content[i] == next_place)
			printf(""BGREEN"%-11d"END"", stack.content[i]);
	}
	else
		printf("%-11d", stack.content[i]);
}

int		min_in_a(t_twostack *set, int min)
{
	int		i;

	if (set->opt == 0)
		return (0);
	if (min < min_stack(set->b.content, set->b.len))
	{
		i = 0;
		while (set->a.content[i] != min)
			i++;
		if (next_val_bigger(set, min) == set->a.content[i + 1]
			&& (i + 1) < set->a.len)
			return (1);
	}
	return (0);
}

int		prev_init(t_twostack *set)
{
	int		min_a;
	int		min_b;

	min_a = min_stack(set->a.content, set->a.len);
	if (min_in_a(set, min_a) == 1)
		return (min_a);
	min_b = min_stack(set->b.content, set->b.len);
	if (min_a < min_b)
		return (min_a - 1);
	return (min_b - 1);
}

void	loop_print(int stop, int prev, t_twostack *set)
{
	int	i;

	i = 0;
	while (i < stop)
	{
		if (set->a.len > i)
		{
			print_val(set->a, i, set->opt, prev);
			if (set->a.content[i] == prev)
				prev = next_val_bigger(set, prev);
		}
		else
			printf("%-11s", " ");
		printf("\t\t");
		if (set->b.len > i)
			print_val(set->b, i, set->opt, prev);
		else
			printf("%-11s", "-");
		printf("\n");
		i++;
	}
}

void	print_stack(t_twostack *set, char *cmd)
{
	int stop;
	int	prev;

	stop = (set->a.len > set->b.len) ? set->a.len : set->b.len;
	prev = prev_init(set);
	printf("\e[2J\e[H");
	if (set->opt == 2)
		printf("Stack_A {"BCYAN"%d"END"}\t\t"
			"Stack_B {"BCYAN"%d"END"}\n\n", set->a.len, set->b.len);
	else
		printf("Stack_A {%d}\t\tStack_B {%d}\n\n", set->a.len, set->b.len);
	loop_print(stop, prev, set);
	if (set->opt == 2)
		printf("\nExec : "BYELLOW"%s"END"\n", cmd);
	else
		printf("\nExec : %s\n", cmd);
	usleep(140000);
}
