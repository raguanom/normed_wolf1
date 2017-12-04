/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:50:28 by raguanom          #+#    #+#             */
/*   Updated: 2017/12/04 15:25:10 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#include <stdio.h>

SDL_Renderer	*init(char *title)
{
	SDL_Window		*win;
	SDL_Renderer	*ren;

	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow(title, 100, 100, 640, 480, SDL_WINDOW_RESIZABLE);
	ren = SDL_CreateRenderer(win, 1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);
	return (ren);
}

void			init_struct(t_wolf *var, char **av)
{
	var->fd = open(av[1], O_RDONLY);
	var->mapheight = get_height(var->fd);
	var->mapwidth = get_width(av[1], var->str, var->line);
	close(var->fd);
	var->fd = open(av[1], O_RDONLY);
	var->mapworld = createworld(var->mapheight, var->mapwidth);
	populatemap(var->mapworld, var->fd);
	close(var->fd);
	var->posx = 2;
	var->posy = 2;
	var->dirx = -1;
	var->diry = 0;
	var->planex = 0;
	var->planey = 0.66;
	var->movex = 0;
	var->movey = 0;
	var->atime = 0;
	var->oldtime = 0;
	var->ren = init("Wolf3d");
	var->width = 640;
	var->height = 480;
}
