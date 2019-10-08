/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 13:58:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/08 16:17:24 by cbretagn         ###   ########.fr       */
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

void				quicksort(t_pile *pl, int sort(int, int), int pivot, int end)
{
	int rotation;

	while (pl->head->value != end)
	{
		if (pl->head->value == pivot)
		{
			rotate(pl);
			write(1, "ra\n", 3);
		}
		else if (!sort(pivot, pl->head->value))
		{
			rotation = 0;
			rev_rotate(pl);
			write(1, "rra\n", 4);
			while (pl->head->value != pivot)
			{
				swap(pl);
				write(1, "sa\n", 3);
				rev_rotate(pl);
				write(1, "rra\n", 4);
				rotation++;
			}
			swap(pl);
			write(1, "sa\n", 3);
			while (rotation-- >= 0)
			{
				rotate(pl);
				write(1, "ra\n", 3);
			}
		}
		else if (sort(pivot, pl->head->value))
		{
			rotate(pl);
			write(1, "ra\n", 3);
		}
	}
	if (sort(pivot, pl->head->value))
	{
		rotate(pl);
		write(1, "ra\n", 3);
	}
}

void				rec_qs(t_pile *pl, int sort(int, int), int pivot, int end)
{
	while (pivot != end)
	{
		quicksort(pl, sort, pivot, end);
		end = pivot;
		pivot = pl->head->value;
	}
}
