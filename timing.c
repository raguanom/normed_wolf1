/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:13:00 by raguanom          #+#    #+#             */
/*   Updated: 2017/12/04 15:05:38 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_time(t_wolf *var)
{
	var->oldtime = var->atime;
	var->atime = SDL_GetTicks();
	var->frametime = (var->atime - var->oldtime) / 1000.0;
	SDL_RenderPresent(var->ren);
	var->movespeed = var->frametime * 30.0;
	var->rotspeed = var->frametime * 6.0;
}
