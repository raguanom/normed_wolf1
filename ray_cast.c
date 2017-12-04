/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:29:30 by raguanom          #+#    #+#             */
/*   Updated: 2017/12/04 15:12:35 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		raycast_draw(t_wolf *var, int *x)
{
	if (0 == var->side)
		var->perpwalldist = (var->mapx - var->rayposx + (1 - var->stepx) / 2)
			/ var->raydirx;
	else
		var->perpwalldist = (var->mapy - var->rayposy + (1 - var->stepy) / 2)
			/ var->raydiry;
	var->lineheight = (int)(var->height / var->perpwalldist);
	var->drawstart = -var->lineheight / 2 + var->height / 2;
	if (var->drawstart < 0)
		var->drawstart = 0;
	var->drawend = var->lineheight / 2 + var->height / 2;
	if (var->drawend >= var->height)
		var->drawend = var->height - 1;
	raycast_render(var, x);
}

static void		raycast_dda(t_wolf *var, int *x)
{
	while (0 == var->hit)
	{
		if (var->sidedistx < var->sidedisty)
		{
			var->sidedistx += var->deltadistx;
			var->mapx += var->stepx;
			var->side = 0;
		}
		else
		{
			var->sidedisty += var->deltadisty;
			var->mapy += var->stepy;
			var->side = 1;
		}
		if (var->mapworld[var->mapx][var->mapy] > 0)
			var->hit = 1;
	}
	raycast_draw(var, x);
}

static void		raycast_step(t_wolf *var, int *x)
{
	if (0 > var->raydirx)
	{
		var->stepx = -1;
		var->sidedistx = (var->rayposx - var->mapx) * var->deltadistx;
	}
	else
	{
		var->stepx = 1;
		var->sidedistx = (var->mapx + 1.0 - var->rayposx) * var->deltadistx;
	}
	if (0 > var->raydiry)
	{
		var->stepy = -1;
		var->sidedisty = (var->rayposy - var->mapy) * var->deltadisty;
	}
	else
	{
		var->stepy = 1;
		var->sidedisty = (var->mapy + 1.0 - var->rayposy) * var->deltadisty;
	}
	raycast_dda(var, x);
}

static void		raycast_init(t_wolf *var, int *x)
{
	var->camerax = 2 * (*x) / (double)var->width - 1;
	var->rayposx = var->posx;
	var->rayposy = var->posy;
	var->raydirx = var->dirx + var->planex * var->camerax;
	var->raydiry = var->diry + var->planey * var->camerax;
	var->mapx = (int)var->rayposx;
	var->mapy = (int)var->rayposy;
	var->sidedistx = 0.00;
	var->sidedisty = 0.00;
	var->deltadistx = sqrt(1 + (var->raydiry * var->raydiry) /
			(var->raydirx * var->raydirx));
	var->deltadisty = sqrt(1 + (var->raydirx * var->raydirx) /
			(var->raydiry * var->raydiry));
	var->perpwalldist = 0.0;
	var->stepx = 0;
	var->stepy = 0;
	var->hit = 0;
	var->side = 0;
	raycast_step(var, x);
}

void			main_raycast(t_wolf *var)
{
	int		x;

	x = 0;
	SDL_SetRenderDrawColor(var->ren, 0, 0, 0, 255);
	SDL_RenderClear(var->ren);
	while (x < var->width)
		raycast_init(var, &x);
}
