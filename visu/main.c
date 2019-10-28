/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:25:48 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/28 18:00:29 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"

int			main(int argc, char **argv)
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	t_pile			*pla;
	t_pile			*plb;
	SDL_Event		e;

	win = init_Sdl();
	rend = SDL_GetRenderer(win);
	if (rend == NULL)
		exit(-1);
	pla = create_pile();
	plb = create_pile();
	if (init_piles(pla, argc, argv) < 0)
	{
		delete_pile(pla);
		delete_pile(plb);
		exit(-1);
	}
	main_loop(rend, pla, plb, &e);
	quit_Sdl(win, rend);
	return (0);
}
