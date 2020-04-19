/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:11:17 by julienngy         #+#    #+#             */
/*   Updated: 2020/04/01 13:14:30 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	mlx_init_img(t_map *map)
{
	map->win.mlx_img = mlx_new_image(map->win.mlx_ptr, map->res_x, map->res_y);
	if (!(map->win.str = (unsigned int *)mlx_get_data_addr(map->win.mlx_img, \
		&map->win.b_p, &map->win.s_l, &map->win.endian)))
		error_exit(map, 2);
	init_img(map);
	mlx_put_image_to_window(map->win.mlx_ptr, \
	map->win.mlx_win, map->win.mlx_img, 0, 0);
	mlx_destroy_image(map->win.mlx_ptr, map->win.mlx_img);
}

static void	game_loop(t_map *map)
{
	mlx_hook(map->win.mlx_win, 2, (1L << 0), key_p, map);
	mlx_hook(map->win.mlx_win, 3, (1L << 1), key_r, map);
	mlx_hook(map->win.mlx_win, 17, (1L << 2), close_cross, map);
	mlx_loop_hook(map->win.mlx_ptr, mlx_init_img, map);
	mlx_loop(map->win.mlx_ptr);
}

void		main_game(t_map *map, int screen)
{
	int i;

	i = 0;
	init_pos(map);
	if (!(init_tex(map)))
		error_exit(map, 4);
	lst_malloc((void **)&map->sprite, map->sprite_nb \
	* sizeof(t_sprite *), map);
	while (i < map->sprite_nb)
	{
		lst_malloc((void **)&map->sprite[i], sizeof(t_sprite), map);
		i++;
	}
	if (!screen)
		game_loop(map);
	else
		init_img(map);
}
