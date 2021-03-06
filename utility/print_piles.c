/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:04:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/02 16:39:46 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <fcntl.h>

void		print_pile(t_pile *pl, int fd)
{
	int		i;
	t_link	*tmp;
	char	*str;

	i = -1;
	tmp = pl->head;
	while (++i < pl->size)
	{
		str = ft_itoa(tmp->value);
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		ft_strdel(&str);
		tmp = tmp->next;
	}
	write(fd, "\n\n", 2);
}
