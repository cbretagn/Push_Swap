/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:25:48 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/29 15:44:04 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"

static void		malloc_error(t_pile *pla, t_pile *plb)
{
	delete_pile(pla);
	delete_pile(plb);
	exit(-1);
}

int				main(int argc, char **argv)
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	t_pile			*pla;
	t_pile			*plb;
	t_gradient		*gradient;

	win = init_sdl();
	rend = SDL_GetRenderer(win);
	if (rend == NULL)
		exit(-1);
	pla = create_pile();
	plb = create_pile();
	if (init_piles(pla, argc, argv) < 0 || pla->size < 50)
		malloc_error(pla, plb);
	SDL_SetWindowOpacity(win, 0.9);
	gradient = init_gradient(pla);
	main_loop(rend, pla, plb, gradient);
	free(gradient);
	gradient = NULL;
	delete_pile(pla);
	delete_pile(plb);
	quit_sdl(win, rend);
	return (0);
}
