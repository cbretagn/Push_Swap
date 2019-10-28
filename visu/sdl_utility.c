/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:02:13 by cbretagn          #+#    #+#             */
/*   Updated: 2019/10/28 17:09:58 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visu.h"

void		get_gradient_color(SDL_Color *color, t_gradient *gradient, int nb)
{
	color->r = START_R + (v_abs(nb - gradient->min) * gradient->r);
	color->g = START_G + (v_abs(nb - gradient->min) * gradient->g);
	color->b = START_B + (v_abs(nb - gradient->min) * gradient->b);
	color->a = 255;
}

void		set_color(SDL_Color *color, int r, int g, int b)
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
	info_pl->length = LENGTH / 5;
	info_pl->width = WIDTH * 4 / 6 / size;
	if (type == 'a')
		info_pl->x = LENGTH / 6;
	else
		info_pl->x = LENGTH / 6 * 4;
	info_pl->y = WIDTH / 6 * 5;
	return(info_pl);
}

t_gradient			*init_gradient(t_pile *pla)
{
	t_gradient	*gradient;
	int			min;
	int			max;
	int			size;

	min = find_min(pla);
	max = find_max(pla);
	size = v_abs(max - min);
	if (!(gradient = (t_gradient *)malloc(sizeof(t_gradient))))
		return (NULL);
	gradient->min = min;
	gradient->r = (START_R - END_R) / size;
	gradient->g = (START_G - END_G) / size;
	gradient->b = (START_B - END_B) / size;
	return (gradient);
}

void				put_rect(SDL_Renderer *rend, t_posinfo *info_pl, SDL_Color *color)
{
	SDL_Rect rect;

	rect.x = info_pl->x;
	rect.y = info_pl->y;
	rect.w = info_pl->length;
	rect.h = info_pl->width;

	SDL_SetRenderDrawColor(rend, color->r, color->g, color->b, color->a);
	SDL_RenderFillRect(rend, &rect);
}
