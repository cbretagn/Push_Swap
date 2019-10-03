/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:49:22 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/02 14:47:35 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		push_sd(t_pile *src, t_pile *dest)
{
	t_link	*tmp;

	if (src->size < 1)
		return ;
	src->size -= 1;
	tmp = src->head;
	if (src->size < 1)
		src->head = NULL;
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		src->head = tmp->next;
	}
	if (dest->head == NULL)
	{
		dest->head = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->prev = dest->head->prev;
		tmp->next = dest->head;
		dest->head->prev->next = tmp;
		dest->head->prev = tmp;
		dest->head = tmp;
	}
	dest->size += 1;
}
