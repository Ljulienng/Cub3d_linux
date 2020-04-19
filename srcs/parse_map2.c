/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:33:15 by julienngy         #+#    #+#             */
/*   Updated: 2020/03/31 13:51:24 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	fill(t_map *map)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (y++ < map->y - 1)
	{
		while (x++ < map->x - 1)
		{
			if (map->map[y][x] == 3)
				map->map[y][x] = 1;
		}
		x = -1;
	}
}

static int	check_beginx(t_map *map, int y, int x)
{
	if (y && x && (map->map[y - 1][x - 1] != 3 && map->map[y - 1][x - 1] != 1))
		return (0);
	else if (y && x != map->x - 1 && \
		(map->map[y - 1][x + 1] != 3 && map->map[y - 1][x + 1] != 1))
		return (0);
	else if (y != map->y - 1 && x && \
		(map->map[y + 1][x - 1] != 3 && map->map[y + 1][x - 1] != 1))
		return (0);
	else if (y != map->y - 1 && x != map->x - 1 && \
		(map->map[y + 1][x + 1] != 3 && map->map[y + 1][x + 1] != 1))
		return (0);
	return (1);
}

static int	check_side(t_map *map, int y, int x)
{
	if (y && (map->map[y - 1][x] != 3 && map->map[y - 1][x] != 1))
		return (0);
	else if (y != map->y - 1 && (map->map[y + 1][x] \
	!= 3 && map->map[y + 1][x] != 1))
		return (0);
	else if (x && (map->map[y][x - 1] != 3 && map->map[y][x - 1] != 1))
		return (0);
	else if (x != map->x - 1 && (map->map[y][x + 1] \
	!= 3 && map->map[y][x + 1] != 1))
		return (0);
	return (check_beginx(map, y, x));
}

void		check_spaces(t_map *map, char **tmp)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (y++ < map->y - 1)
	{
		while (x++ < map->x - 1)
		{
			if (map->map[y][x] == 3)
				if (!(check_side(map, y, x)))
					error_exit(map, 1);
		}
		x = -1;
	}
	fill(map);
}
