/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:09:09 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/02 15:58:49 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile			*create_pile(void)
{
	t_pile	*ret;

	if (!(ret = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	ret->head = NULL;
	ret->size = 0;
	return (ret);
}

static t_link	*create_link(int nb)
{
	t_link *ret;

	if (!(ret = (t_link *)malloc(sizeof(t_link))))
		exit(0);
	ret->value = nb;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void			delete_link(t_link *del)
{
	del->next->prev = del->prev;
	del->prev->next = del->next;
	free(del);
	del = NULL;
}

t_pile			*add_link(t_pile *pl, int nb)
{
	t_link	*add;
	t_link	*tmp;

	if (!(add = create_link(nb)))
		exit(0);
	pl->size += 1;
	if (pl->head == NULL)
		pl->head = &add;
	else
	{
		tmp = *(pl->head);
		if (!(tmp->prev) && !(tmp->next))
		{
			tmp->next = add;
			tmp->prev = add;
			add->next = tmp;
			add->prev = tmp;
		}
		else
		{
			tmp->prev->next = add;
			add->prev = tmp->prev;
			add->next = tmp;
			tmp->prev = add;
		}
	}
	return (pl);
}

void			delete_pile(t_pile *pl)
{
	int		i;
	t_link	*curr;
	t_link	*tmp;

	i = -1;
	tmp = *(pl->head);
	while (++i < pl->size - 1)
	{
		curr = tmp->next;
		delete_link(curr);
	}
	if (tmp)
		delete_link(tmp);
	free(pl);
	pl = NULL;
}

