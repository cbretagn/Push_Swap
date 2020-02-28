/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:42:37 by cbretagn          #+#    #+#             */
/*   Updated: 2020/02/27 17:43:32 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
