/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:49:20 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/30 15:08:55 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void		casetype2(t_pile *pl, t_pile *instru)
{
	if (pl->size == 3)
	{
		rrb_rra(pl, instru, 1);
		sb_sa(pl, instru, 1);
	}
	else
	{
		rb_ra(pl, instru, 1);
		sb_sa(pl, instru, 1);
		rrb_rra(pl, instru, 1);
	}
}

static void		casetype4(t_pile *pl, t_pile *instru)
{
	if (pl->size == 3)
		rrb_rra(pl, instru, 1);
	else
	{
		rb_ra(pl, instru, 1);
		sb_sa(pl, instru, 1);
		rrb_rra(pl, instru, 1);
		sb_sa(pl, instru, 1);
	}
}

static void		casetype5(t_pile *pl, t_pile *instru)
{
	if (pl->size == 3)
	{
		sb_sa(pl, instru, 1);
		rrb_rra(pl, instru, 1);
	}
	else
	{
		sb_sa(pl, instru, 1);
		rb_ra(pl, instru, 1);
		sb_sa(pl, instru, 1);
		rrb_rra(pl, instru, 1);
		sb_sa(pl, instru, 1);
	}
}

static void		casetype6(t_pile *pl, t_pile *instru)
{
	if (pl->size == 3)
		rb_ra(pl, instru, 1);
	else
	{
		sb_sa(pl, instru, 1);
		rb_ra(pl, instru, 1);
		sb_sa(pl, instru, 1);
		rrb_rra(pl, instru, 1);
	}
}

void			handle_three(t_pile *pl, t_pile *instru)
{
	int		a;
	int		b;
	int		c;

	a = pl->head->value;
	b = pl->head->next->value;
	c = pl->head->next->next->value;
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
		casetype2(pl, instru);
	else if (a > b && b < c && a < c)
		sb_sa(pl, instru, 1);
	else if (a < b && b > c && a > c)
		casetype4(pl, instru);
	else if (a > b && b > c && a > c)
		casetype5(pl, instru);
	else
		casetype6(pl, instru);
}
