/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:18:41 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/21 15:11:05 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile		*parse_string(char *str, t_pile *pl)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			pl = add_link(pl, ft_atoi(str + i));
		else
		{
			delete_pile(pl);
			return (NULL);
		}
		while (str[i] <= '9' && str[i] >= '0')
			i++;
		if (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
		{
			delete_pile(pl);
			return (NULL);
		}
		while (str[i] == ' ' || str[i] == '\n')
			i++;
	}
	return (pl);
}
