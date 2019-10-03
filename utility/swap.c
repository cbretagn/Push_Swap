/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:27:27 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/02 14:48:34 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		swap(t_pile *pl)
{
	int		tmp;

	if (!(pl->head))
		return ;
	tmp = pl->head->value;
	pl->head->value = pl->head->next->value;
	pl->head->next->value = tmp;
}
