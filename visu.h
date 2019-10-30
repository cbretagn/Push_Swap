/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:24:06 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/30 15:25:17 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "push_swap.h"
# include <SDL.h>

# define LENGTH 1400
# define WIDTH 1000
# define X_PB 800
# define X_PA 200
# define Y_PL 900
# define L_REC 400

# define START_R 0x64
# define START_G 0x41
# define START_B 0xa5
# define END_R 0x2a
# define END_G 0x08
# define END_B 0x45

typedef struct	s_posinfo
{
	int		x;
	int		y;
	int		length;
	int		width;
	int		size;
}				t_posinfo;

typedef struct	s_gradient
{
	float	r;
	float	g;
	float	b;
	int		min;
}				t_gradient;

int				init_piles(t_pile *pla, int argc, char **argv);
SDL_Window		*init_sdl();
void			quit_sdl(SDL_Window *win, SDL_Renderer *rend);
int				event_loop(void);
void			color_background(SDL_Renderer *rend);

void			main_loop(SDL_Renderer *rend, t_pile *pla,
					t_pile *plb, t_gradient *gradient);

void			get_gradient_color(SDL_Color *color,
						t_gradient *gradient, int nb);
void			set_color(SDL_Color *color, int r, int g, int b);
t_posinfo		*init_info(char type, int size);
t_gradient		*init_gradient(t_pile *pla);
void			put_rect(SDL_Renderer *rend, t_posinfo *info_pl,
					SDL_Color *color, int y);

int				find_min(t_pile *pl);
int				find_max(t_pile *pl);
int				v_abs(int nb);

void			display_rend(SDL_Renderer *rend, int size);
void			free_posinfo(t_posinfo *pla, t_posinfo *plb);
#endif
