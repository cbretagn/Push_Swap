/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:04:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/21 14:10:34 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int					error_checker(int size, char **tab)
{
	int		i;
	int		j;

	i = 0;
	if (size < 2)
		return (-1);
	if (size == 2)
		return (1);
	while (++i < size)
	{
		j = -1;
		if (ft_strlen(tab[i]) > 11
				|| (ft_strlen(tab[i]) > 10
					&& tab[i][0] != '-' && tab[i][0] != '+'))
			return (-1);
		if (tab[i][0] == '-' || tab[i][0] == '+')
			j++;
		while (tab[i][++j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (-1);
		}
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

int					check_sorted(t_pile *pl)
{
	int		i;
	t_link	*tmp;

	i = 0;
	tmp = pl->head;
	while (++i < pl->size)
	{
		if (tmp->value > tmp->next->value)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
