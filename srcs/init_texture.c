/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:14:31 by julienngy         #+#    #+#             */
/*   Updated: 2020/04/02 12:44:47 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "mlx.h"

static int		convert_xpm_img(t_map *map)
{
	if (!(map->texture[NORTH].img_ptr = \
		mlx_xpm_file_to_image(map->win.mlx_ptr, map->text_path.no, \
		&map->texture[NORTH].width, &map->texture[NORTH].height)))
		return (0);
	if (!(map->texture[SOUTH].img_ptr = \
		mlx_xpm_file_to_image(map->win.mlx_ptr, map->text_path.so, \
		&map->texture[SOUTH].width, &map->texture[SOUTH].height)))
		return (0);
	if (!(map->texture[WEST].img_ptr = \
		mlx_xpm_file_to_image(map->win.mlx_ptr, map->text_path.we, \
		&map->texture[WEST].width, &map->texture[WEST].height)))
		return (0);
	if (!(map->texture[EAST].img_ptr = \
		mlx_xpm_file_to_image(map->win.mlx_ptr, map->text_path.ea, \
		&map->texture[EAST].width, &map->texture[EAST].height)))
		return (0);
	if (!(map->texture[SPRITE].img_ptr = \
		mlx_xpm_file_to_image(map->win.mlx_ptr, map->text_path.spr, \
		&map->texture[SPRITE].width, &map->texture[SPRITE].height)))
		return (0);
	return (1);
}

static void		get_tex_info(t_map *map)
{
	map->texture[NORTH].img = (unsigned int *)\
	mlx_get_data_addr(map->texture[NORTH].img_ptr, &map->texture[NORTH].b_p_p, \
	&map->texture[NORTH].s_l, &map->texture[NORTH].endian);
	map->texture[SOUTH].img = (unsigned int *)\
	mlx_get_data_addr(map->texture[SOUTH].img_ptr, &map->texture[SOUTH].b_p_p, \
	&map->texture[SOUTH].s_l, &map->texture[SOUTH].endian);
	map->texture[WEST].img = (unsigned int *)\
	mlx_get_data_addr(map->texture[WEST].img_ptr, &map->texture[WEST].b_p_p, \
	&map->texture[WEST].s_l, &map->texture[WEST].endian);
	map->texture[EAST].img = (unsigned int *)\
	mlx_get_data_addr(map->texture[EAST].img_ptr, &map->texture[EAST].b_p_p, \
	&map->texture[EAST].s_l, &map->texture[EAST].endian);
	map->texture[SPRITE].img = (unsigned int *)\
	mlx_get_data_addr(map->texture[SPRITE].img_ptr, \
	&map->texture[SPRITE].b_p_p, &map->texture[SPRITE].s_l,\
	&map->texture[SPRITE].endian);
}

int				init_tex(t_map *map)
{
	if (!(convert_xpm_img(map)))
		return (0);
	get_tex_info(map);
	return (1);
}
