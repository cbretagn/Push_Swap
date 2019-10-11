/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheese.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:13:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/11 18:44:17 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				*create_array(t_pile *pl, int size)
{
	int		*tab;
	t_link	*tmp;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	tmp = pl->head;
	while (--size >= 0)
	{
		tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (tab);
}

static void		tab_swap(int *tab, int i, int j)
{
	int		tmp;

	tmp = tab[i];
	tab[i] = tab[j];
	tab[j] = tmp;
}

static int		partition(int *tab, int head, int tail)
{
	int		pivot;
	int		i;
	int		j;

	pivot = tab[tail];
	i = head - 1;
	j = head;
	while (j < tail)
	{
		if (tab[j] <= pivot)
		{
			i++;
			tab_swap(tab, i, j);
		}
		j++;
	}
	tab_swap(tab, i + 1, tail);
	return (i + 1);
}

void				tab_quicksort(int *tab, int head, int tail)
{
	int		pivot;

	if (head < tail)
	{
		pivot = partition(tab, head, tail);
		tab_quicksort(tab, head, pivot - 1);
		tab_quicksort(tab, pivot + 1, tail);
	}
}
