/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:30:55 by julienngy         #+#    #+#             */
/*   Updated: 2020/04/01 13:01:02 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	error_msgs(int nb)
{
	if (nb)
		ft_putstr_fd("Error: ", 2);
	else
		ft_putstr_fd("A screenshot have been made\n", 1);
	nb == 1 ? ft_putstr_fd("Invalid map\n", 2) : 0;
	nb == 2 ? ft_putstr_fd("Malloc error\n", 2) : 0;
	nb == 3 ? ft_putstr_fd("File Missing\n", 2) : 0;
	nb == 4 ? ft_putstr_fd("Texture error\n", 2) : 0;
	nb == 5 ? ft_putstr_fd("Texture error\n", 2) : 0;
}

int			error_exit(t_map *map, int nb)
{
	if (map->win.mlx_img)
		mlx_destroy_image(map->win.mlx_ptr, map->win.mlx_img);
	free(map->text_path.no);
	free(map->text_path.so);
	free(map->text_path.we);
	free(map->text_path.ea);
	free(map->text_path.spr);
	ft_lstclear(&(map->map_tmp), &free);
	ft_lstclear(&(map->trash), &free);
	free(map);
	error_msgs(nb);
	exit(0);
}
