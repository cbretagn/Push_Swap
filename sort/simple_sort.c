/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:48:01 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/10 18:25:21 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void		place_left(t_pile *pla, t_pile *plb, t_pile *instru, int left)
{
	while (--left > 0)
	{
		rev_rotate(pla);
		push_instru(instru, RRA);
	}
	push_sd(plb, pla);
	push_instru(instru, PA);
}

static void		place_right(t_pile *pla, t_pile *plb, t_pile *instru, int right)
{
	while (--right > 0)
	{
		rotate(pla);
		push_instru(instru, RA);
	}
	push_sd(plb, pla);
	push_instru(instru, PB);
}

static void		place_value(t_pile *pla, t_pile *plb, t_pile *instru)
{
	int		right;
	int		left;
	t_link	*tmp;

	right = 0;
	left = 0;
	tmp = pla->head;
	while (plb->head->value > tmp->value)
	{
		tmp = tmp->next;
		right++;
	}
	tmp = pla->head->prev;
	while (plb->head->value < tmp->value)
	{
		tmp = tmp->prev;
		right++;
	}
	if (left < right && left > 0)
		place_left(pla, plb, instru, left);
	else
		place_right(pla, plb, instru, right);
}

static int		in_tab(int value, int *tab, int curr_size)
{
	int		i;

	i = -1;
	while (++i < curr_size)
	{
		if (value == tab[i])
			return (-1);
	}
	return (1);
}

void			simple_sort(t_pile *pla, t_pile *plb, t_pile *instru)
{
	int		*tab;
	int		curr_size;
	int		min = 2;
	int 	max = 8;

	tab = (int *)malloc(sizeof(int) * pla->size);
	curr_size = 0;
	while (curr_size < pla->size)
	{
		if ((pla->head->value < pla->head->next->value 
				&& pla->head->value > pla->head->prev->value) || pla->head->value == min || pla->head->value == max)
		{
			if (!(in_tab(pla->head->value, tab, curr_size)))
			{
				tab[curr_size] = pla->head->value;
				curr_size++;
			}
			rotate(pla);
			push_instru(instru, RA);
		}
		else
		{
			push_sd(pla, plb);
			push_instru(instru, PB);
			place_value(pla, plb, instru);
			tab[curr_size] = pla->head->value;
			curr_size++;
			rotate(pla);
			push_instru(instru, RA);
		}
	}
}

//parcourt la liste
//si mal place push sur b
//ra ou rra selon jusqu le placer
//ope inver
