/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:51:00 by cbretagn          #+#    #+#             */
/*   Updated: 2019/11/07 12:46:36 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int				input_error(t_pile *pla, t_pile *plb)
{
	if (pla)
		delete_pile(pla);
	if (plb)
		delete_pile(plb);
	write(1, "Error\n", 6);
	return (0);
}

static void				cleanup(t_pile *pla, t_pile *plb, t_pile *instru)
{
	if (pla)
		delete_pile(pla);
	if (plb)
		delete_pile(plb);
	if (instru)
		delete_pile(instru);
}

static int				main_fun(t_pile *pla, t_pile *plb, t_pile *instru)
{
	if (check_sorted(pla) < 0)
	{
		full_sort(pla, plb, instru);
		return (0);
	}
	else
	{
		cleanup(pla, plb, instru);
		return (-1);
	}
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
	if (error_checker(argc, argv) < 0)
		return (input_error(pla, plb));
	else
	{
		while (++i < argc)
			pla = add_link(pla, ft_atoi(argv[i]));
	}
	if (check_doublons(pla) < 0)
		return (input_error(pla, plb));
	instru = create_pile();
	return (main_fun(pla, plb, instru));
}
