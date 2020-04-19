/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:35:10 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/02 13:14:20 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		loop_sprites2(t_map *map, int y, int *stripe, int i)
{
	int color;
	int d;
	int	texty;

	while (y < map->sprite[i]->drawe_y)
	{
		d = y * 256 - map->res_y * 128 + map->sprite[i]->sprite_h * 128;
		texty = ((d * map->texture[SPRITE].height) /\
		map->sprite[i]->sprite_h) / 256;
		color = abs(map->texture[SPRITE].img\
		[(map->texture[SPRITE].s_l / 4) * texty + map->textx]);
		if (color != 16777215)
			map->win.str[map->res_x * y + *stripe] = color;
		y++;
	}
}

void			loop_sprites(t_map *map, int i)
{
	int stripe;
	int y;

	stripe = map->sprite[i]->draws_x;
	y = map->sprite[i]->draws_y;
	while (stripe < map->sprite[i]->drawe_x)
	{
		map->textx = (256 * (stripe - (-map->sprite[i]->sprite_w \
			/ 2 + map->sprite[i]->spritescreenx)) * map->texture[SPRITE].width \
			/ map->sprite[i]->sprite_w) / 256;
		y = map->sprite[i]->draws_y;
		if (map->sprite[i]->transformy > 0 && stripe > 0 && stripe \
		< map->res_x && map->sprite[i]->transformy < map->zbuffer[stripe])
			loop_sprites2(map, y, &stripe, i);
		stripe++;
	}
}

static void		init_sprites3(t_map *map, int i)
{
	map->sprite[i]->draws_y = -map->sprite[i]->sprite_h / 2 + map->res_y / 2;
	if (map->sprite[i]->draws_y < 0)
		map->sprite[i]->draws_y = 0;
	map->sprite[i]->drawe_y = map->sprite[i]->sprite_h / 2 + map->res_y / 2;
	if (map->sprite[i]->drawe_y >= map->res_y)
		map->sprite[i]->drawe_y = map->res_y - 1;
	map->sprite[i]->sprite_w = abs((int)((double)map->res_y \
		/ map->sprite[i]->transformy));
	map->sprite[i]->draws_x = -map->sprite[i]->sprite_w \
		/ 2 + map->sprite[i]->spritescreenx;
	if (map->sprite[i]->draws_x < 0)
		map->sprite[i]->draws_x = 0;
	map->sprite[i]->drawe_x = map->sprite[i]->sprite_w \
		/ 2 + map->sprite[i]->spritescreenx;
	if (map->sprite[i]->drawe_x >= map->res_x)
		map->sprite[i]->drawe_x = map->res_x - 1;
}

static void		init_sprites2(t_map *map, int i)
{
	map->sprite[i]->transformx = map->sprite[i]->invdet \
	* (map->player.dir_y * map->sprite[i]->spritex - \
	map->player.dir_x * map->sprite[i]->spritey);
	map->sprite[i]->transformy = map->sprite[i]->invdet * \
	(-map->player.plane_y * map->sprite[i]->spritex + \
	map->player.plane_x * map->sprite[i]->spritey);
	map->sprite[i]->spritescreenx = (int)(((double)map->res_x / 2) * \
		(1.0 + (map->sprite[i]->transformx / map->sprite[i]->transformy)));
	map->sprite[i]->sprite_h = abs((int)((double)map->res_y \
		/ (map->sprite[i]->transformy)));
}

void			init_sprites(t_map *map)
{
	int i;

	i = 0;
	while (i < map->sprite_nb &&\
		(map->sprite[i]->map_x || map->sprite[i]->map_y))
	{
		map->sprite[i]->spritex = (map->sprite[i]->map_x + 0.5)\
		- map->player.pos_x;
		map->sprite[i]->spritey = (map->sprite[i]->map_y + 0.5)\
		- map->player.pos_y;
		map->sprite[i]->invdet = 1.0 / (map->player.plane_x * \
		map->player.dir_y - map->player.dir_x * map->player.plane_y);
		init_sprites2(map, i);
		init_sprites3(map, i);
		i++;
	}
}
