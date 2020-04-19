/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnguyen <jnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:04:58 by julienngy         #+#    #+#             */
/*   Updated: 2020/03/10 14:33:15 by jnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	convert_rgb(t_map *map, char *line, int fc)
{
	int r;
	int g;
	int	b;
	int i;

	i = 0;
	r = ft_atoi(line);
	while (ft_isdigit(line[i]))
		i++;
	g = ft_atoi(line + ++i);
	while (ft_isdigit(line[i]))
		i++;
	b = ft_atoi(line + ++i);
	if (!fc)
		map->floor = 65536 * r + 256 * g + b;
	else
		map->ceiling = 65536 * r + 256 * g + b;
}

void	sky_floor(t_map *map)
{
	int		x;
	int		sky;

	x = 0;
	while (x < (map->win.s_l / 4) * map->res_y / 2)
	{
		map->win.str[x] = map->ceiling;
		x++;
	}
	while (x < (map->win.s_l / 4) * map->res_y)
	{
		map->win.str[x] = map->floor;
		x++;
	}
}
