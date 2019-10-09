/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheese.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:13:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/09 18:29:59 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//cpy lst into array
//
//quicksort hoare partition scheme
//
//push on b
//pull back on a

#include "../push_swap.h"

int			*create_array(t_pile *pl)
{
	int		*tab;
	t_link	*tmp;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * pl->size)))
		return (NULL);
	tmp = pl->head->next;
	tab[0] = pl->head->value;
	while (tmp->value != tab[0])
	{
		tab[++i] = tmp->value;
		tmp = tmp->next;
	}
	return (tab);
}

int			partition(int *tab, int head, int tail)
{
	int		i;
	int		j;
	int		pivot;
	int		tmp;

	pivot = (tail - head) / 2;
	i = head;
	j = tail;
	while (42)
	{
		while (i <= tail && tab[i] < pivot)
			i++;
		while (j >= head && tab[j] > pivot)
			j--;
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		if (i >= j)
			return (i);
	}
	return (i);
}

int			main(int argc, char **argv)
{
	int	*tab;
	tab = malloc(sizeof(int) * argc - 1);
	int i = 0;
	while (++i < argc)
		tab[i - 1] = ft_atoi(argv[i]);
	int ret = partition(tab, 0, argc - 2);
	i = -1;
	while (++i < argc - 1)
	{
		ft_putnbr(tab[i]);
		ft_putchar(' ');
	}
	ft_putnbr(ret);
	return (0);
}
