/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:33:39 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/16 14:36:01 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//struct : pla + plb + instru + lst_plb = t_pile *
//
//fun rec_pa(size, pla, lst_plb, instru);
//fun sort_plb
//

static void			handle_two(t_stru *pl, int size, char i)
{
	if (size == 2)
	{
		if (i == 0)
		{
			if (pl->plb->head->value < pl->plb->head->next->value)
				sb_sa(pl->plb, pl->instru, 0);
		}
		else
		{
			if (pl->pla->head->value > pl->pla->head->next->value)
				sb_sa(pl->pla, pl->instru, 1);
		}
	}
	if (i == 0)
	{
		while (--size >= 0)
			pb_pa(pl->plb, pl->pla, pl->instru, 1);
	}
}

static int			find_pivot(t_pile *pl, int size)
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

static void			sort_pla(int size, t_stru *pl)
{
	int		pivot;
	int		tmp;
	int		count_ra;
	int		count_pb;

	count_ra = 0;
	count_pb = 0;
	if (size <= 2)
		handle_two(pl, size, 1);
	else
	{
		pivot = find_pivot(pl->pla, size);
		tmp = size;
		while (--tmp >= 0)
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
		if (size != pl->pla->size && pl->pla->size > 1)
		{
			if (count_ra < pl->pla->size - count_ra)
			{
				tmp = count_ra;
				while (--tmp >= 0)
					rrb_rra(pl->pla, pl->instru, 1);
			}
			else
			{
				tmp = pl->pla->size - count_ra;
				while (--tmp >= 0)
					rb_ra(pl->pla, pl->instru, 1);
			}
		}
		sort_pla(count_ra, pl);
	}
}

static void			sort_plb(int size, t_stru *pl)
{
	int		pivot;
	int		tmp;
	int		count_rb;
	int		count_pa;

	count_rb = 0;
	count_pa = 0;
	if (size <= 2)
	{
		handle_two(pl, size, 0);
		rotate(pl->lst_pb);
		delete_link(pl->lst_pb->head->prev);
		pl->lst_pb->size -= 1;
	}
	else
	{
		pivot = find_pivot(pl->plb, size);
		tmp = size;
		while (--tmp >= 0)
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
		sort_pla(count_pa, pl);
	}
}

void				full_sort(t_pile *pla, t_pile *plb, t_pile *instru)
{
	t_pile *lst_pb;
	t_stru	*pl;

	if (!(pl = (t_stru *)malloc(sizeof(t_stru))))
		return ;
	lst_pb = create_pile();
	pl->pla = pla;
	pl->plb = plb;
	pl->instru = instru;
	lst_pb = create_pile();
	pl->lst_pb = lst_pb;
	sort_pla(pl->pla->size, pl);
	while (pl->lst_pb->size > 0)
		sort_plb(pl->lst_pb->head->value, pl);
}