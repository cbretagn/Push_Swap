/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utility2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:08:44 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/30 15:23:33 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"

void			display_rend(SDL_Renderer *rend, int size)
{
	SDL_RenderPresent(rend);
	if (size >= 200)
		SDL_Delay(10);
	else if (size >= 100)
		SDL_Delay(100);
	else
		SDL_Delay(500);
}

void			free_posinfo(t_posinfo *pla, t_posinfo *plb)
{
	free(pla);
	pla = NULL;
	free(plb);
	plb = NULL;
}
