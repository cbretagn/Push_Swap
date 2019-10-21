/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:40:31 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/16 15:35:31 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				find_pivot(t_pile *pl, int size)
{
	int		*tab;
	int		ret;

	if (!(tab = create_array(pl, size)))
		return (-1);
	tab_quicksort(tab, 0, size - 1);
	ret = tab[size / 2];
	free(tab);
	tab = NULL;
	return (ret);
}

int				divide_pile_pla(int size, t_stru *pl)
{
	int		pivot;
	int		count_pb;
	int		count_ra;

	pivot = find_pivot(pl->pla, size);
	count_pb = 0;
	count_ra = 0;
	while (--size >= 0)
	{
		if (pl->pla->head->value <= pivot)
		{
			pb_pa(pl->pla, pl->plb, pl->instru, 0);
			count_pb++;
		}
		else
		{
			rb_ra(pl->pla, pl->instru, 1);
			count_ra++;
		}
	}
	pl->lst_pb = add_link(pl->lst_pb, count_pb);
	rev_rotate(pl->lst_pb);
	return (count_ra);
}

static void		replace_plb(int count_rb, t_stru *pl)
{
	if (count_rb != pl->plb->size && pl->plb->size > 1)
	{
		if (count_rb < pl->plb->size - count_rb)
		{
			while (--count_rb >= 0)
				rrb_rra(pl->plb, pl->instru, 0);
		}
		else
		{
			count_rb = pl->plb->size - count_rb;
			while (--count_rb >= 0)
				rb_ra(pl->plb, pl->instru, 0);
		}
	}
}

int				divide_pile_plb(int size, t_stru *pl)
{
	int		pivot;
	int		count_rb;
	int		count_pa;

	count_rb = 0;
	count_pa = 0;
	pivot = find_pivot(pl->plb, size);
	while (--size >= 0)
	{
		if (pl->plb->head->value > pivot)
		{
			pb_pa(pl->plb, pl->pla, pl->instru, 1);
			count_pa++;
		}
		else
		{
			rb_ra(pl->plb, pl->instru, 0);
			count_rb++;
		}
	}
	pl->lst_pb->head->value = count_rb;
	replace_plb(count_rb, pl);
	return (count_pa);
}
