/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:51:00 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/16 14:21:55 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int				input_error(t_pile *pla, t_pile *plb)
{
	delete_pile(pla);
	delete_pile(plb);
	write(1, "Error\n", 6);
	return (0);
}

int						main(int argc, char **argv)
{
	t_pile	*pla;
	t_pile	*plb;
	t_pile	*instru;
	int		i;

	i = 0;
	pla = create_pile();
	plb = create_pile();
	instru = create_pile();
	if (error_checker(argc, argv) < 0)
		return (input_error(pla, plb));
	while (++i < argc)
		pla = add_link(pla, ft_atoi(argv[i]));
	if (check_doublons(pla) < 0)
		return (input_error(pla, plb));
	if (check_sorted(pla) < 0)
		full_sort(pla, plb, instru);
	print_instru(instru);
	delete_pile(pla);
	delete_pile(plb);
	delete_pile(instru);
	return (0);
}
