/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:52:36 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/29 16:37:59 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"

int			find_min(t_pile *pl)
{
	int		ret;
	t_link	*tmp;

	tmp = pl->head;
	ret = tmp->value;
	tmp = tmp->next;
	while (tmp != pl->head)
	{
		if (tmp->value < ret)
			ret = tmp->value;
		tmp = tmp->next;
	}
	return (ret);
}

int			find_max(t_pile *pl)
{
	int		ret;
	t_link	*tmp;

	tmp = pl->head;
	ret = tmp->value;
	tmp = tmp->next;
	while (tmp != pl->head)
	{
		if (tmp->value > ret)
			ret = tmp->value;
		tmp = tmp->next;
	}
	return (ret);
}

int			v_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
