/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:58:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/10 15:59:33 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void				two_piles_qs(t_pile *pla, t_pile *plb)
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
		{
			push_sd(pla, plb);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(pla);
			write(1, "ra\n", 3);
		}
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

void				quicksort(t_pile *pl, int sort(int, int), int pivot
		, int end, t_pile *instru)
{
	int rotation;

	while (pl->head->value != end)
	{
		if (pl->head->value == pivot)
		{
			rotate(pl);
			push_instru(instru, RA);
		}
		else if (!sort(pivot, pl->head->value))
		{
			rotation = 0;
			rev_rotate(pl);
			push_instru(instru, RRA);
			while (pl->head->value != pivot)
			{
				swap(pl);
				push_instru(instru, SA);
				rev_rotate(pl);
				push_instru(instru, RRA);
				rotation++;
			}
			swap(pl);
			push_instru(instru, SA);
			while (rotation-- >= 0)
			{
				rotate(pl);
				push_instru(instru, RA);
			}
		}
		else if (sort(pivot, pl->head->value))
		{
			rotate(pl);
			push_instru(instru, RA);
		}
	}
	if (sort(pivot, pl->head->value))
	{
		rotate(pl);
		push_instru(instru, RA);
	}
}
