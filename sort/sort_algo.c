/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:33:39 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/16 17:00:39 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void			sort_pla(int size, t_stru *pl)
{
	int		tmp;
	int		count_ra;

	if (size <= 2)
		handle_two(pl, size, 1);
	else
	{
		count_ra = divide_pile_pla(size, pl);
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
	int		count_pa;

	if (size <= 2)
	{
		handle_two(pl, size, 0);
		if (pl->lst_pb->size == 1)
		{
			free(pl->lst_pb->head);
			pl->lst_pb->head = NULL;
		}
		else
		{
			rotate(pl->lst_pb);
			delete_link(pl->lst_pb->head->prev);
		}
		pl->lst_pb->size -= 1;
	}
	else
	{
		count_pa = divide_pile_plb(size, pl);
		sort_pla(count_pa, pl);
	}
}

void				full_sort(t_pile *pla, t_pile *plb, t_pile *instru)
{
	t_stru		*pl;

	if (!(pl = (t_stru *)malloc(sizeof(t_stru))))
		return ;
	pl->pla = pla;
	pl->plb = plb;
	pl->instru = instru;
	pl->lst_pb = create_pile();
	sort_pla(pl->pla->size, pl);
	while (pl->lst_pb->size > 0)
		sort_plb(pl->lst_pb->head->value, pl);
	print_instru(pl->instru);
	delete_pile(pl->instru);
	delete_pile(pl->pla);
	delete_pile(pl->plb);
	free(pl->lst_pb);
	pl->lst_pb = NULL;
	free(pl);
	pl = NULL;
}
