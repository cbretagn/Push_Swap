/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:24:06 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/28 18:00:24 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "push_swap.h"
# include <SDL.h>

# define LENGTH 1280
# define WIDTH 960
# define START_R 255
# define START_G 255
# define START_B 255
# define END_R 0
# define END_G 0
# define END_B 0

typedef struct s_posinfo
{
	int		x;
	int		y;
	int		length;
	int		width;
	int		size;
}				t_posinfo;

typedef struct	s_gradient
{
	float 	r;
	float 	g;
	float 	b;
	int		min;
}				t_gradient;

int				init_piles(t_pile *pla, int argc, char **argv);
SDL_Window		*init_Sdl();
void			quit_Sdl(SDL_Window *win, SDL_Renderer *rend);

int				main_loop(SDL_Renderer *rend, t_pile *pla,
					t_pile *plb, SDL_Event *e);

void			get_gradient_color(SDL_Color *color, t_gradient *gradient, int nb);
void			set_color(SDL_Color *color, int r, int g, int b);
t_posinfo		*init_info(char type, int size);
t_gradient		*init_gradient(t_pile *pla);
void			put_rect(SDL_Renderer *rend, t_posinfo *info_pl,
					SDL_Color *color, int y);

int				find_min(t_pile *pl);
int				find_max(t_pile *pl);
int				v_abs(int nb);
# endif
