/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:37:27 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/02 14:50:49 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		rotate(t_pile *pl)
{
	if (pl->head)
		pl->head = pl->head->next;
}

void		rev_rotate(t_pile *pl)
{
	if (pl->head)
		pl->head = pl->head->prev;
}
