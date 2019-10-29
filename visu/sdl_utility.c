/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:02:13 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/29 15:46:44 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"

void			get_gradient_color(SDL_Color *color,
						t_gradient *gradient, int nb)
{
	color->r = START_R + ((nb - gradient->min) * gradient->r);
	color->g = START_G + ((nb - gradient->min) * gradient->g);
	color->b = START_B + ((nb - gradient->min) * gradient->b);
	color->a = 255;
}

void			set_color(SDL_Color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = 255;
}

t_posinfo		*init_info(char type, int size)
{
	t_posinfo	*info_pl;

	if (!(info_pl = (t_posinfo *)malloc(sizeof(t_posinfo))))
		return (NULL);
	info_pl->size = size;
	info_pl->length = L_REC;
	info_pl->width = WIDTH * 5 / 6 / size;
	if (type == 'a')
		info_pl->x = X_PA;
	else
		info_pl->x = X_PB;
	info_pl->y = Y_PL;
	return (info_pl);
}

t_gradient		*init_gradient(t_pile *pla)
{
	t_gradient	*gradient;
	int			min;
	int			max;
	int			size;

	min = find_min(pla);
	max = find_max(pla);
	size = v_abs(max - min) + 1;
	if (!(gradient = (t_gradient *)malloc(sizeof(t_gradient))))
		return (NULL);
	gradient->min = min;
	gradient->r = (END_R - START_R) / (float)size;
	gradient->g = (END_G - START_G) / (float)size;
	gradient->b = (END_B - START_B) / (float)size;
	return (gradient);
}

void			put_rect(SDL_Renderer *rend, t_posinfo *info_pl,
						SDL_Color *color, int y)
{
	SDL_Rect rect;

	rect.x = info_pl->x;
	rect.y = y;
	rect.w = info_pl->length;
	rect.h = info_pl->width;
	SDL_SetRenderDrawColor(rend, color->r, color->g, color->b, color->a);
	SDL_RenderFillRect(rend, &rect);
}
