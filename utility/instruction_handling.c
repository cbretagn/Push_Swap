/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:05:53 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/11 18:29:05 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	vabs(int nb)
{
	if (nb > 0)
		return (nb);
	return (nb * -1);
}

void		push_instru(t_pile *instru, int value)
{
	int		last;

	if (instru->head == NULL)
	{
		instru = add_link(instru, value);
		return ;
	}
	last = instru->head->prev->value;
	if (vabs(last - value) == 1)
	{
		if (instru->head->prev != instru->head)
			delete_link(instru->head->prev);
		else
		{
			free(instru->head);
			instru->head = NULL;
		}
		instru->size -= 1;
		return ;
	}
	else
		instru = add_link(instru, value);
}

void			print_instru(t_pile *instru)
{
	t_link	*tmp;
	char	*tab[19];
	
	tmp = instru->head;
	tab[0] = "sa\n";
	tab[2] = "sb\n";
	tab[4] = "ra\n";
	tab[5] = "rra\n";
	tab[7] = "rb\n";
	tab[8] = "rrb\n";
	tab[10] = "pa\n";
	tab[12] = "pb\n";
	tab[14] = "rr\n";
	tab[16] = "rrr\n";
	tab[18] = "ss\n";
	ft_putendl(tab[tmp->value]);
	tmp = tmp->next;
	while (tmp != instru->head)
	{
		ft_putstr(tab[tmp->value]);
		tmp = tmp->next;
	}
}
