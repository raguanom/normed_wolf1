/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:01:52 by raguanom          #+#    #+#             */
/*   Updated: 2017/12/04 15:55:02 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		drawlinee(SDL_Renderer *ren, int x, int y1, int y2)
{
	while (++y1 < y2)
		SDL_RenderDrawPoint(ren, x, y1);
}

static void		render_floor(t_wolf *var, int *x, int *i)
{
	(*i) = var->drawend + 2;
	if (*i >= var->drawend && *i < var->height)
	{
		SDL_SetRenderDrawColor(var->ren, 210, 180, 140, 255);
		drawlinee(var->ren, *x, *i, var->height);
		(*i)++;
	}
	(*x)++;
}

void			raycast_render(t_wolf *var, int *x)
{
	int			i;

	i = -1;
	if (++i < var->drawstart + 1)
	{
		SDL_SetRenderDrawColor(var->ren, 10, 130, 235, 255);
		drawlinee(var->ren, *x, i, var->drawstart);
	}
	SDL_SetRenderDrawColor(var->ren, 0, 0, 0, 255);
	if (0 == var->side)
	{
		if (0 > var->stepx)
			SDL_SetRenderDrawColor(var->ren, 255, 0, 0, 255);
		else
			SDL_SetRenderDrawColor(var->ren, 0, 255, 0, 255);
	}
	else
	{
		if (0 > var->stepy)
			SDL_SetRenderDrawColor(var->ren, 0, 0, 255, 255);
		else
			SDL_SetRenderDrawColor(var->ren, 255, 255, 0, 255);
	}
	drawlinee(var->ren, *x, var->drawstart + 1, var->drawend);
	render_floor(var, x, &i);
}
