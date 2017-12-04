#ifndef SDL_H
# define SDL_H

/*
**	Global includes:
*/

#include <SDL2/SDL.h>

/*
**	Drawing functions:
*/

void	draw_line(SDL_Renderer *ren, int x1, int y1, int x2, int y2);

/*
**	Miscelaneous functions:
*/

int		abs(int n);
void	swap(int *n1, int *n2);

#endif
