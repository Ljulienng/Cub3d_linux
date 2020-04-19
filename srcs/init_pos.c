/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:41:36 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/02 13:01:29 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_pos2(t_map *map)
{
	if (map->player.direction == 'W')
	{
		map->player.dir_x = -1;
		map->player.dir_y = 0;
		map->player.plane_x = 0;
		map->player.plane_y = -0.66;
	}
	else if (map->player.direction == 'E')
	{
		map->player.dir_x = 1;
		map->player.dir_y = 0;
		map->player.plane_x = 0;
		map->player.plane_y = 0.66;
	}
}

void		init_pos(t_map *map)
{
	if (map->player.direction == 'N')
	{
		map->player.dir_x = 0;
		map->player.dir_y = -1;
		map->player.plane_x = 0.66;
		map->player.plane_y = 0;
	}
	else if (map->player.direction == 'S')
	{
		map->player.dir_x = 0;
		map->player.dir_y = 1;
		map->player.plane_x = -0.66;
		map->player.plane_y = 0;
	}
	else
		init_pos2(map);
}

int			init_y(t_map *map, char *av)
{
	int		y;
	int		fd;
	int		ret;
	char	*line;

	y = 0;
	if (!(fd = open(av, O_RDONLY)))
		error_exit(map, 2);
	while ((ret = get_next_line(fd, &line)))
	{
		if (line[0] == '1' || line[0] == ' ')
			y++;
		ft_strdel(&line);
	}
	if (line[0] == '1' || line[0] == ' ')
		y++;
	ft_strdel(&line);
	close(fd);
	return (y);
}
