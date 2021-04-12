/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:12:57 by tsannie           #+#    #+#             */
/*   Updated: 2021/04/12 13:29:30 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	be_charset(char a, char charset)
{
	if (a == charset)
		return (1);
	return (0);
}

static int	count_word(const char *str, char charset)
{
	int		n;
	int		word;
	int		i;

	i = 0;
	word = 0;
	while (str[i])
	{
		n = 0;
		while (str[i] && be_charset(str[i], charset) == 1)
			i++;
		while (str[i] && be_charset(str[i], charset) == 0)
		{
			n++;
			i++;
		}
		if (n > 0)
			word++;
	}
	return (word);
}

static void	alloc(char **res, const char *str, char charset)
{
	int		n;
	int		word;
	int		i;

	i = 0;
	word = 1;
	while (str[i])
	{
		n = 0;
		while (str[i] && be_charset(str[i], charset) == 1)
			i++;
		while (str[i] && be_charset(str[i], charset) == 0)
		{
			n++;
			i++;
		}
		if (n > 0)
		{
			res[word] = malloc(sizeof(char) * (n + 1));
			word++;
		}
	}
}

static void	fill(char **res, const char *str, char charset)
{
	int		n;
	int		word;
	int		i;

	i = 0;
	word = 1;
	while (str[i])
	{
		n = 0;
		while (str[i] && be_charset(str[i], charset) == 1)
			i++;
		while (str[i] && be_charset(str[i], charset) == 0)
		{
			res[word][n] = str[i];
			n++;
			i++;
		}
		if (n > 0)
		{
			res[word][n] = '\0';
			word++;
		}
	}
}

char		**split_arg(const char *str, char charset)
{
	char	**res;

	if (str == NULL)
		return (NULL);
	if (!(res = malloc(sizeof(char *) * (count_word(str, charset) + 2))))
		return (NULL);
	res[0] = "start";
	alloc(res, str, charset);
	fill(res, str, charset);
	res[count_word(str, charset) + 1] = 0;
	return (res);
}