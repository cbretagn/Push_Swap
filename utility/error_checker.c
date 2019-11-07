/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:04:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/11/07 12:50:56 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int			check_max(char *str)
{
	int		i;
	int		ret;

	ret = 0;
	i = (str[0] == '-' || str[0] == '+') ? 0 : -1;
	ret = str[++i] > '2' ? ret - 1 : ret;
	ret = str[++i] > '1' ? ret - 1 : ret;
	ret = str[++i] > '4' ? ret - 1 : ret;
	ret = str[++i] > '7' ? ret - 1 : ret;
	ret = str[++i] > '4' ? ret - 1 : ret;
	ret = str[++i] > '8' ? ret - 1 : ret;
	ret = str[++i] > '3' ? ret - 1 : ret;
	ret = str[++i] > '6' ? ret - 1 : ret;
	ret = str[++i] > '4' ? ret - 1 : ret;
	ret = ((str[++i] > '7' && str[0] != '-')
			|| (str[0] == '-' && str[i] > '8')) ? ret - 1 : ret;
	return (ret);
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
	if (i > 11 || ((str[i] != '-' || str[i] != '+') && i > 10))
		return (-1);
	if (i == 10 || i == 11)
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

static int			check_one(int to_check, t_pile *pl)
{
	int		i;
	int		count;
	t_link	*tmp;

	count = 0;
	i = -1;
	tmp = pl->head;
	while (++i < pl->size)
	{
		if (tmp->value == to_check)
			count++;
		tmp = tmp->next;
		if (count > 1)
			return (-1);
	}
	return (0);
}

int					check_doublons(t_pile *pl)
{
	int		i;
	t_link	*tmp;

	i = -1;
	tmp = pl->head;
	while (++i < pl->size)
	{
		if (check_one(tmp->value, pl) < 0)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
