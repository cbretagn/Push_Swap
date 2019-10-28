/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preview.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:51:09 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/28 17:09:56 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"
#include <stdio.h>

void		put_pile(SDL_Renderer *rend, t_pile *pl, t_posinfo *info_pl,
						t_gradient *gradient)
{
	t_link		*tmp;
	SDL_Color	color;

	tmp = pl->head->prev;
	SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
	SDL_RenderClear(rend);
	set_color(&color, START_R, START_G, START_B);
	while (tmp != pl->head)
	{
		get_gradient_color(&color, gradient, tmp->value);
		put_rect(rend, info_pl, &color);
		tmp = tmp->prev;
		info_pl->y -= info_pl->width;
	}
	SDL_RenderPresent(rend);
}


int			main_loop(SDL_Window *win, SDL_Renderer *rend,
				t_pile *pla, t_pile *plb)
{
	SDL_Event 	e;
	int			loop;
	t_posinfo	*info_pla;
	t_posinfo	*info_plb;
	t_gradient	*gradient;
	//int			end_instru;

	(void)win;
	(void)plb;
	loop = 42;
	info_pla = init_info('a', pla->size);
	info_plb = init_info('b', pla->size);
	gradient = init_gradient(pla);
	//end_instru = 1;
	put_pile(rend, pla, info_pla, gradient);
	while (loop)
	{
		//if end instru gnl _ need to add gnl
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				loop = 0;
		}
	}
	return (0);
}
