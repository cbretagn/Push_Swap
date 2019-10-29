/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:23:13 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/29 15:46:29 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"

int				init_piles(t_pile *pla, int argc, char **argv)
{
	int		i;

	i = 0;
	if (error_checker(argc, argv) < 0)
		return (-1);
	else if (error_checker(argc, argv) == 1)
	{
		pla = parse_string(argv[1], pla);
		if (pla == NULL)
			return (-1);
	}
	else
	{
		while (++i < argc)
			pla = add_link(pla, ft_atoi(argv[i]));
	}
	if (check_doublons(pla) < 0)
		return (-1);
	return (0);
}

SDL_Window		*init_sdl(void)
{
	SDL_Renderer	*rend;
	SDL_Window		*win;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit(-1);
	win = SDL_CreateWindow("Push_swap", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, LENGTH, WIDTH, SDL_WINDOW_SHOWN);
	if (win == NULL)
		exit(-1);
	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (rend == NULL)
		exit(-1);
	return (win);
}

void			quit_sdl(SDL_Window *win, SDL_Renderer *rend)
{
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

int				event_loop(void)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			return (0);
	}
	return (42);
}

void			color_background(SDL_Renderer *rend)
{
	SDL_SetRenderDrawColor(rend, 0x24, 0x24, 0x3e, 255);
	SDL_RenderClear(rend);
}
