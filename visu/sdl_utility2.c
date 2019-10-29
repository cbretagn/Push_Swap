/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utility2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:08:44 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/29 15:44:20 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"

void			display_rend(SDL_Renderer *rend, int size)
{
	(void)size;
	SDL_RenderPresent(rend);
	SDL_Delay(20);
}

void			free_posinfo(t_posinfo *pla, t_posinfo *plb)
{
	free(pla);
	pla = NULL;
	free(plb);
	plb = NULL;
}
