/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:57:17 by jnguyen           #+#    #+#             */
/*   Updated: 2020/03/31 12:53:09 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rot_right(t_map *map)
{
	double old_dirx;
	double old_planex;

	old_dirx = map->player.dir_x;
	old_planex = map->player.plane_x;
	map->player.dir_x = map->player.dir_x * cos(0.05) \
		- map->player.dir_y * sin(0.05);
	map->player.dir_y = old_dirx * sin(0.05) + map->player.dir_y * cos(0.05);
	map->player.plane_x = map->player.plane_x * cos(0.05) \
	- map->player.plane_y * sin(0.05);
	map->player.plane_y = old_planex * sin(0.05) \
	+ map->player.plane_y * cos(0.05);
}

void	rot_left(t_map *map)
{
	double old_dirx;
	double old_planex;

	old_dirx = map->player.dir_x;
	old_planex = map->player.plane_x;
	map->player.dir_x = map->player.dir_x * cos(-0.05) \
	- map->player.dir_y * sin(-0.05);
	map->player.dir_y = old_dirx * sin(-0.05) + map->player.dir_y * cos(-0.05);
	map->player.plane_x = map->player.plane_x * cos(-0.05) \
	- map->player.plane_y * sin(-0.05);
	map->player.plane_y = old_planex * sin(-0.05) \
	+ map->player.plane_y * cos(-0.05);
}
