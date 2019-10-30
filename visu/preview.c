/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:51:09 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/30 15:23:53 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"
#include <stdio.h>

static int				exec_instru2(char *str, t_pile *pla, t_pile *plb)
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

static int				exec_instru(char *str, t_pile *pla, t_pile *plb)
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

void					put_pile(SDL_Renderer *rend, t_pile *pl,
							t_posinfo *info_pl, t_gradient *gradient)
{
	t_link		*tmp;
	SDL_Color	color;
	int			y;

	if (pl == NULL || pl->head == NULL)
		return ;
	tmp = pl->head->prev;
	y = info_pl->y;
	while (tmp != pl->head)
	{
		get_gradient_color(&color, gradient, tmp->value);
		put_rect(rend, info_pl, &color, y);
		tmp = tmp->prev;
		y -= info_pl->width;
	}
	get_gradient_color(&color, gradient, tmp->value);
	put_rect(rend, info_pl, &color, y);
}

int						next_instru(t_pile *pla, t_pile *plb)
{
	char	*str;
	int		ret;

	ret = get_next_line(0, &str);
	if (ret > 0)
	{
		exec_instru(str, pla, plb);
		ft_strdel(&str);
	}
	return (ret);
}

void					main_loop(SDL_Renderer *rend, t_pile *pla,
								t_pile *plb, t_gradient *gradient)
{
	int				loop;
	t_posinfo		*info_pla;
	t_posinfo		*info_plb;
	int				end_instru;

	loop = 42;
	info_pla = init_info('a', pla->size);
	info_plb = init_info('b', pla->size);
	end_instru = 1;
	put_pile(rend, pla, info_pla, gradient);
	SDL_RenderPresent(rend);
	while (loop)
	{
		loop = event_loop();
		if (end_instru > 0)
			end_instru = next_instru(pla, plb);
		if (end_instru > 0)
		{
			color_background(rend);
			put_pile(rend, pla, info_pla, gradient);
			put_pile(rend, plb, info_plb, gradient);
			display_rend(rend, info_pla->size);
		}
	}
	free_posinfo(info_pla, info_plb);
}
