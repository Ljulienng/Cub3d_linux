/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:57:35 by jnguyen           #+#    #+#             */
/*   Updated: 2020/02/29 00:25:57 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		move_forward(t_map *map)
{
	int horizontal;
	int vertical;

	horizontal = map->map[(int)map->player.pos_y]\
		[(int)(map->player.pos_x + map->player.dir_x * 0.08)];
	vertical = map->map[(int)(map->player.pos_y + map->player.dir_y * 0.08)]\
		[(int)map->player.pos_x];
	if (horizontal == 0 || horizontal > 2)
		map->player.pos_x += map->player.dir_x * 0.08;
	if (vertical == 0 || vertical > 2)
		map->player.pos_y += map->player.dir_y * 0.08;
}

void		move_backward(t_map *map)
{
	int	horizontal;
	int vertical;

	horizontal = map->map[(int)map->player.pos_y]\
		[(int)(map->player.pos_x - map->player.dir_x * 0.08)];
	vertical = map->map[(int)(map->player.pos_y - map->player.dir_y * 0.08)]\
		[(int)map->player.pos_x];
	if (horizontal == 0 || horizontal > 2)
		map->player.pos_x -= map->player.dir_x * 0.08;
	if (vertical == 0 || vertical > 2)
		map->player.pos_y -= map->player.dir_y * 0.08;
}

void		strafe_left(t_map *map)
{
	int	horizontal;
	int vertical;

	horizontal = map->map[(int)map->player.pos_y]\
		[(int)(map->player.pos_x - map->player.plane_x * 0.08)];
	vertical = map->map[(int)(map->player.pos_y - map->player.plane_y * 0.08)]\
		[(int)map->player.pos_x];
	if (horizontal == 0 || horizontal > 2)
		map->player.pos_x -= map->player.plane_x * 0.08;
	if (vertical == 0 || vertical > 2)
		map->player.pos_y -= map->player.plane_y * 0.08;
}

void		strafe_right(t_map *map)
{
	int	horizontal;
	int vertical;

	horizontal = map->map[(int)map->player.pos_y]\
		[(int)(map->player.pos_x + map->player.plane_x * 0.08)];
	vertical = map->map[(int)(map->player.pos_y + map->player.plane_y * 0.08)]\
		[(int)map->player.pos_x];
	if (horizontal == 0 || horizontal > 2)
		map->player.pos_x += map->player.plane_x * 0.08;
	if (vertical == 0 || vertical > 2)
		map->player.pos_y += map->player.plane_y * 0.08;
}
