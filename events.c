/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:16:55 by raguanom          #+#    #+#             */
/*   Updated: 2017/12/04 15:24:00 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	close_prog(t_wolf *var)
{
	if (var->event.key.keysym.sym == SDLK_ESCAPE)
	{
		exit(0);
	}
}

void	turn_left(t_wolf *var)
{
	if (var->event.key.keysym.sym == SDLK_LEFT)
	{
		var->olddirx = var->dirx;
		var->dirx = var->dirx * cos(var->rotspeed) -
			var->diry * sin(var->rotspeed);
		var->diry = var->olddirx * sin(var->rotspeed) +
			var->diry * cos(var->rotspeed);
		var->oldplanex = var->planex;
		var->planex = var->planex * cos(var->rotspeed) -
			var->planey * sin(var->rotspeed);
		var->planey = var->oldplanex * sin(var->rotspeed) +
			var->planey * cos(var->rotspeed);
	}
	close_prog(var);
}

void	turn_right(t_wolf *var)
{
	if (var->event.key.keysym.sym == SDLK_RIGHT)
	{
		var->olddirx = var->dirx;
		var->dirx = var->dirx * cos(-var->rotspeed) -
			var->diry * sin(-var->rotspeed);
		var->diry = var->olddirx * sin(-var->rotspeed) +
			var->diry * cos(-var->rotspeed);
		var->oldplanex = var->planex;
		var->planex = var->planex * cos(-var->rotspeed) -
			var->planey * sin(-var->rotspeed);
		var->planey = var->oldplanex * sin(-var->rotspeed) +
			var->planey * cos(-var->rotspeed);
	}
	turn_left(var);
}

void	input(t_wolf *var)
{
	if (var->event.key.keysym.sym == SDLK_UP)
	{
		if (var->mapworld[(int)var->movex][(int)var->posy] == 0)
			var->posx += var->dirx * var->movespeed;
		if (var->mapworld[(int)var->posy][(int)var->movey] == 0)
			var->posy += var->diry * var->movespeed;
	}
	if (var->event.key.keysym.sym == SDLK_DOWN)
	{
		if (var->mapworld[(int)var->movex][(int)var->posy] == 0)
			var->posx -= var->dirx * var->movespeed;
		if (var->mapworld[(int)var->posx][(int)var->movey] == 0)
			var->posy -= var->diry * var->movespeed;
	}
	turn_right(var);
}

void	poll_events(t_wolf *var)
{
	while (SDL_PollEvent(&var->event))
	{
		var->movex = var->posx + var->dirx * var->movespeed;
		var->movey = var->posy + var->diry * var->movespeed;
		if (var->event.type == SDL_KEYDOWN)
		{
			input(var);
		}
	}
}
