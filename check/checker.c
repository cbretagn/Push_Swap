/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:04:16 by cbretagn          #+#    #+#             */
/*   Updated: 2020/02/27 17:54:59 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int			input_error(t_pile *pla, t_pile *plb)
{
	if (pla)
		delete_pile(pla);
	if (plb)
		delete_pile(plb);
	write(1, "Error\n", 6);
	exit(0);
}

static int			exec_instru2(char *str, t_pile *pla, t_pile *plb)
{
	if (!ft_strcmp(str, "rrr"))
	{
		rev_rotate(pla);
		rev_rotate(plb);
	}
	else if (!ft_strcmp(str, "rr"))
	{
		rotate(pla);
		rotate(plb);
	}
	else if (!ft_strcmp(str, "ss"))
	{
		swap(pla);
		swap(plb);
	}
	else
		return (-1);
	return (0);
}

static int			exec_instru(char *str, t_pile *pla, t_pile *plb)
{
	if (!ft_strcmp(str, "ra"))
		rotate(pla);
	else if (!ft_strcmp(str, "rb"))
		rotate(plb);
	else if (!ft_strcmp(str, "rra"))
		rev_rotate(pla);
	else if (!ft_strcmp(str, "rrb"))
		rev_rotate(plb);
	else if (!ft_strcmp(str, "pa"))
		push_sd(plb, pla);
	else if (!ft_strcmp(str, "pb"))
		push_sd(pla, plb);
	else if (!ft_strcmp(str, "sa"))
		swap(pla);
	else if (!ft_strcmp(str, "sb"))
		swap(plb);
	else
		return (exec_instru2(str, pla, plb));
	return (0);
}

static int			handle_piles(t_pile *pla, t_pile *plb)
{
	char	*str;
	int		ret;

	while ((ret = get_next_line(0, &str) > 0))
	{
		if (exec_instru(str, pla, plb) < 0)
		{
			ft_strdel(&str);
			return (input_error(pla, plb));
		}
		ft_strdel(&str);
	}
	if (ret == -1)
		return (input_error(pla, plb));
	if (plb->head == NULL && check_sorted(pla) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	delete_pile(pla);
	delete_pile(plb);
	return (0);
}

int					main(int argc, char **argv)
{
	int		i;
	t_pile	*pla;
	t_pile	*plb;

	pla = create_pile();
	plb = create_pile();
	i = 0;
	if (error_checker(argc, argv) < 0)
		return (input_error(pla, plb));
	else
	{
		while (++i < argc)
			pla = add_link(pla, ft_atoi(argv[i]));
	}
	if (check_doublons(pla) < 0)
		return (input_error(pla, plb));
	if (handle_piles(pla, plb) < 0)
		return (-1);
	return (0);
}
