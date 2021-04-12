/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:46:01 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/12 10:47:02 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	long long	res;
	int			i;
	int			neg;

	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\n')
		i++;
	neg = (str[i] == '-') ? 1 : 0;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((neg == 1) ? -res : res);
}
