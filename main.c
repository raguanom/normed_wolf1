/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:33:15 by raguanom          #+#    #+#             */
/*   Updated: 2017/12/04 16:00:39 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		error_arg_count(char **av)
{
	ft_putstr("Error : program usage -->> ");
	ft_putstr(av[0]);
	ft_putendl(" <<-- [input_file].wolf3d.");
	exit(ERROR_ARG_COUNT);
}

void		error_file_descriptor(char **av)
{
	ft_putstr("Error : file descriptor -->> ");
	ft_putstr(av[1]);
	ft_putendl(" <<-- does not exist, or does not have correct permmisions.");
	exit(ERROR_FILE_DESCRIPTOR);
}

void		error_file_extention(char **av)
{
	ft_putstr("Error : file extention -->> ");
	ft_putstr(av[1]);
	ft_putendl(" <<-- is not a valid .wolf3d file.");
	exit(ERROR_FILE_EXTENTION);
}

void		main_loop(t_wolf *var, char **av)
{
	init_struct(var, av);
	while (1)
	{
		main_raycast(var);
		init_time(var);
		poll_events(var);
	}
}

int			main(int ac, char **av)
{
	int		ret;
	t_wolf	var;

	if (ac == 2)
	{
		if (ft_strrchr(av[1], '.') == NULL)
			error_file_extention(av);
		if (ft_strcmp(".wolf3d", ft_strrchr(av[1], '.')) != 0)
			error_file_extention(av);
		if ((ret = open(av[1], O_RDONLY)) == -1)
			error_file_descriptor(av);
		else
			main_loop(&var, av);
	}
	else
		error_arg_count(av);
	return (0);
}
