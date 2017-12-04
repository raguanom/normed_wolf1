/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguanom <raguanom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 09:27:18 by raguanom          #+#    #+#             */
/*   Updated: 2017/12/04 13:27:04 by raguanom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				get_height(int fd)
{
	char		*line;
	int			ret;

	ret = 0;
	while ((get_next_line(fd, &line)) > 0)
		ret++;
	return (ret);
}

int				get_width(char *file_name, char **str, char *line)
{
	int			fd;
	int			num_points;
	int			i;

	fd = open(file_name, O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		num_points = 0;
		str = ft_strsplit(line, ',');
		i = -1;
		while (str[++i] != 0)
			num_points++;
	}
	i = -1;
	while (str[++i] != 0)
		ft_memdel(((void *)&str[i]));
	free(str);
	close(fd);
	return (num_points);
}

int				**createworld(int height, int width)
{
	int			**ret;
	int			i;

	i = 0;
	if (!(ret = (int**)malloc(sizeof(int*) * height)))
		return (NULL);
	while (i < height + 1)
	{
		if (!(ret[i] = (int*)malloc(sizeof(int) * width)))
			return (NULL);
		i++;
	}
	return (ret);
}

void			populatemap(int **ary, int fd)
{
	int			i;
	int			j;
	int			k;
	char		*line;
	char		**str;

	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		str = ft_strsplit(line, ',');
		k = -1;
		j = -1;
		while (str[++k] != 0)
			(ary)[i][++j] = ft_atoi(str[k]);
		k = -1;
		while (str[++k] != 0)
			ft_strdel(&str[k]);
		free(str);
		i++;
	}
}
