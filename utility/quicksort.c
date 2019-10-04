/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:58:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/04 16:13:23 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void				first_qs(t_pile *pla, t_pile *plb)
{
	int		pivot;
	int		size;
	int		i;

	pivot = pla->head->value;
	size = pla->size;
	i = -1;
	while (++i < size)
	{
		if (pla->head->value < pivot)
			push_sd(pla, plb);
		else
			rotate(pla);
	}
}

int					croissant(int pivot, int value)
{
	if (value > pivot)
		return (1);
	return (0);
}

int					decroissant(int pivot, int value)
{
	if (value < pivot)
		return (1);
	return (0);
}

void				medium_qs(t_pile *pl, int pivot, int end, int sort(int, int))
{
	int		nb_rotation;

	nb_rotation = 0;
	while (pl->head->value != end)
	{
		if (sort(pivot, pl->head->value) && !sort(pivot, pl->head->next->value))
		{
			write(1, "sa\n", 3);
			swap(pl);
		}
		else
		{
			write(1, "ra\n", 3);
			rotate(pl);
			nb_rotation++;
		}
	}
	while (nb_rotation > 0)
	{
		rev_rotate(pl);
		write(1, "rra\n", 4);
		nb_rotation--;
		if (sort(pivot, pl->head->value) && !sort(pivot, pl->head->next->value))
		{
			swap(pl);
			write(1, "sa\n", 3);
		}
	}
}
