/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:57:38 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/02 13:12:59 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		esc_game(t_map *map)
{
	ft_putstr_fd("successfuly left the game\n", 2);
	mlx_destroy_image(map->win.mlx_ptr, map->win.mlx_img);
	free(map->text_path.no);
	free(map->text_path.so);
	free(map->text_path.we);
	free(map->text_path.ea);
	free(map->text_path.spr);
	ft_lstclear(&map->map_tmp, &free);
	ft_lstclear(&map->trash, &free);
	exit(0);
}

int				key_p(int keycode, t_map *map)
{
	if (keycode == 122)
		map->key |= KEY_W;
	else if (keycode == 115)
		map->key |= KEY_S;
	else if (keycode == 113)
		map->key |= KEY_A;
	else if (keycode == 100)
		map->key |= KEY_D;
	else if (keycode == 65361)
		map->key |= KEY_LEFT;
	else if (keycode == 65363)
		map->key |= KEY_RIGHT;
	else if (keycode == 65307)
		map->key |= KEY_ESC;
}

int				key_r(int keycode, t_map *map)
{
	if (keycode == 122)
		map->key -= KEY_W;
	else if (keycode == 115)
		map->key -= KEY_S;
	else if (keycode == 113)
		map->key -= KEY_A;
	else if (keycode == 100)
		map->key -= KEY_D;
	else if (keycode == 65361)
		map->key -= KEY_LEFT;
	else if (keycode == 65363)
		map->key -= KEY_RIGHT;
	else if (keycode == 65307)
		map->key -= KEY_ESC;
}

void			moves(t_map *map)
{
	if (map->key & KEY_W)
		move_forward(map);
	if (map->key & KEY_S)
		move_backward(map);
	if (map->key & KEY_A)
		strafe_left(map);
	if (map->key & KEY_D)
		strafe_right(map);
	if (map->key & KEY_RIGHT)
		rot_right(map);
	if (map->key & KEY_LEFT)
		rot_left(map);
	if (map->key & KEY_ESC)
		esc_game(map);
}

int				close_cross(void *param)
{
	ft_putstr_fd("successfuly left the game\n", 2);
	(void)param;
	exit(0);
}
