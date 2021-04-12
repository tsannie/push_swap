/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:50:40 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/12 10:50:58 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	max_int(char *str)
{
	long long	value;

	value = ft_atoll(str);
	if (value > I_MAX || value < I_MIN)
		return (0);
	return (1);
}

int			ft_isnumber(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			sign++;
		else if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if ((ft_strlen(str) > 11) || sign > 1)
		return (0);
	if (sign == 1)
	{
		if (str[0] != '+' && str[0] != '-')
			return (0);
	}
	return (max_int(str));
}
