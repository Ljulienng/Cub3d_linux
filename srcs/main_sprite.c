/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 13:05:54 by julienngy         #+#    #+#             */
/*   Updated: 2020/04/02 13:12:43 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			sprite_loop(t_map *map)
{
	int i;

	i = 0;
	update_sprite(map);
	sort_sprite(map);
	init_sprites(map);
	while (i <= map->sprite_nb &&\
		(map->sprite[i]->map_x || map->sprite[i]->map_y))
	{
		loop_sprites(map, i);
		i++;
	}
}
