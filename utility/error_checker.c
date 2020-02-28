/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:04:16 by cbretagn          #+#    #+#             */
/*   Updated: 2020/02/27 17:53:22 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int			part2(char *str, int i)
{
	if (str[++i] > '8')
		return (-1);
	if (str[i] < '8')
		return (0);
	if (str[++i] > '3')
		return (-1);
	if (str[i] < '3')
		return (0);
	if (str[++i] > '6')
		return (-1);
	if (str[i] < '6')
		return (0);
	if (str[++i] > '4')
		return (-1);
	if (str[i] < '4')
		return (0);
	if (str[++i] > '7')
		return (-1);
	return (0);
}

static int			check_max(char *str)
{
	int		i;

	i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	if (str[i] > '2')
		return (-1);
	if (str[i] < '2')
		return (0);
	if (str[++i] > '1')
		return (-1);
	if (str[i] < '1')
		return (0);
	if (str[++i] > '4')
		return (-1);
	if (str[i] < '4')
		return (0);
	if (str[++i] > '7')
		return (-1);
	if (str[i] < '7')
		return (0);
	if (str[++i] > '4')
		return (-1);
	if (str[i] < '4')
		return (0);
	return (part2(str, i));
}

static int			is_not_int(char *str)
{
	int		i;

	i = (str[0] == '-' || str[0] == '+') ? 0 : -1;
	if (str[0] != '-' && str[0] != '+' && !(str[0] >= '0' && str[0] <= '9'))
		return (-1);
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	if (i > 11 || (!(str[0] == '-' || str[0] == '+') && i > 10))
		return (-1);
	if ((i == 10 && str[0] != '-' && str[0] != '+')
			|| (i == 11 && (str[0] == '-' || str[0] == '+')))
		return (check_max(str));
	return (0);
}

int					error_checker(int size, char **tab)
{
	int		i;

	i = 0;
	if (size == 1)
		exit(0);
	if (size < 2)
		return (-1);
	while (++i < size)
	{
		if (is_not_int(tab[i]) < 0)
			return (-1);
	}
	return (0);
}
