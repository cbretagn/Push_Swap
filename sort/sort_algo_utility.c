/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:38:58 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/11 18:29:03 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		sb_sa(t_pile *pl, t_pile *instru, int i)
{
	int		value;

	swap(pl);
	value = (i == 0) ? SB : SA;
	push_instru(instru, value);
}

void		rb_ra(t_pile *pl, t_pile *instru, int i)
{
	int		value;

	rotate(pl);
	value = (i == 0) ? RB : RA;
	push_instru(instru, value);
}

void		rrb_rra(t_pile *pl, t_pile *instru, int i)
{
	int		value;

	rev_rotate(pl);
	value = (i == 0) ? RRB : RRA;
	push_instru(instru, value);
}

void		pb_pa(t_pile *pls, t_pile *pld, t_pile *instru, int i)
{
	int		value;

	value = (i == 0) ? PB : PA;
	push_sd(pls, pld);
	push_instru(instru, value);
}
