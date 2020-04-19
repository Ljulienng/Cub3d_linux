/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:33:06 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/01 13:15:14 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	define_x(t_map *map, char **tmp)
{
	int max;
	int i;
	int j;

	i = 0;
	j = 0;
	max = 0;
	while (tmp[i][0] != '\n' && i < map->y - 1)
	{
		if (ft_strlen(tmp[i]) > max)
			max = ft_strlen(tmp[i]);
		i++;
	}
	map->x = max;
}

static int	parse_line(t_map *map, char *line, int y)
{
	int i;
	int j;

	j = 0;
	i = 0;
	lst_malloc((void **)&map->map[y], map->x * sizeof(int), map);
	while (j != map->x)
	{
		if (ft_validarg(line[i], map) && line[i])
		{
			map->map[y][j++] = line[i] - 48;
			if (line[i] - 48 == 2)
				map->sprite_nb++;
			i++;
		}
		else if (line[i] == ' ' && line[i])
		{
			map->map[y][j++] = '3' - 48;
			i++;
		}
		else if (j != map->x)
			map->map[y][j++] = '3' - 48;
	}
	return (1);
}

int			parse_map(t_map *map, char **tmp)
{
	int i;
	int j;

	i = map->y - 1;
	define_x(map, tmp);
	lst_malloc((void **)&map->map, map->y * sizeof(int *), map);
	while (i + 1 && map->x)
	{
		if (!(parse_line(map, tmp[map->player.x], i)))
			error_exit(map, 1);
		i--;
		map->player.x--;
	}
	check_spaces(map, tmp);
	i = map->y - 1;
	while (i > -1)
	{
		free(tmp[i]);
		i--;
	}
	return (1);
}
