/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:02:09 by raguanom          #+#    #+#             */
/*   Updated: 2017/12/04 15:17:50 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <sdl.h>
# include <stdio.h>
# include <math.h>

# include "./libft/libft.h"

# define ERROR_ARG_COUNT -1
# define ERROR_FILE_DESCRIPTOR -2
# define ERROR_FILE_EXTENTION -3

/*
**  struct:
*/
typedef struct		s_wolf
{
	SDL_Renderer	*ren;
	SDL_Event		event;
	char			*line;
	char			**str;
	int				fd;
	int				width;
	int				height;
	int				**mapworld;
	int				mapwidth;
	int				mapheight;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			olddirx;
	double			planex;
	double			planey;
	double			oldplanex;
	double			atime;
	double			oldtime;
	double			frametime;
	double			movespeed;
	double			rotspeed;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			movex;
	double			movey;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				hit;
	int				side;
	int				stepx;
	int				stepy;
	int				lineheight;
	int				drawstart;
	int				drawend;
}					t_wolf;

/*
**  Functions:
*/
int					get_height(int fd);
int					get_width(char *file_name, char **str, char *line);
int					**createworld(int height, int width);
void				populatemap(int **ary, int fd);
void				init_struct(t_wolf *var, char **av);
SDL_Renderer		*init(char *title);
void				drawline(SDL_Renderer *ren, int x1, int y1, int y2);
void				main_raycast(t_wolf *var);
void				raycast_render(t_wolf *var, int *x);
void				poll_events(t_wolf *var);
void				init_time(t_wolf *var);

#endif
