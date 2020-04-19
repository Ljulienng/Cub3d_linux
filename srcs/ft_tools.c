/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:28:20 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/02 12:58:16 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_validarg(char c, t_map *map)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'E' || \
		c == 'W' || c == 'S')
		return (1);
	else if (c == ' ')
		return (0);
	else
		return (0);
}

int		ft_is_set(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	lst_malloc(void **to_malloc, size_t size, t_map *map)
{
	t_list *new;

	if (!(*to_malloc = ft_calloc(1, size)))
		error_exit(map, 2);
	if (!(new = ft_lstnew(*to_malloc)))
		error_exit(map, 2);
	ft_lstadd_front(&(map->trash), new);
}

void	store_sprite(t_map *map)
{
	int i;

	i = 0;
	while (map->sprite[i]->map_x != 0 || map->sprite[i]->map_y != 0)
	{
		if (map->sprite[i]->map_x == map->map_x
			&& map->sprite[i]->map_y == map->map_y)
			return ;
		i++;
	}
	if (i > map->sprite_nb)
		map->sprite_nb = i;
	map->sprite[i]->map_x = map->map_x;
	map->sprite[i]->map_y = map->map_y;
	map->sprite[i]->distance = (map->player.pos_x - \
	(map->sprite[i]->map_x + 0.5)) * (map->player.pos_x \
	- (map->sprite[i]->map_x + 0.5)) + (map->player.pos_y \
	- (map->sprite[i]->map_y + 0.5)) * (map->player.pos_y - \
	(map->sprite[i]->map_y + 0.5));
}

void	sort_sprite(t_map *map)
{
	int		i;
	void	*add;

	i = 0;
	while (i < map->sprite_nb - 1)
	{
		if (map->sprite[i]->distance < map->sprite[i + 1]->distance)
		{
			add = map->sprite[i];
			map->sprite[i] = map->sprite[i + 1];
			map->sprite[i + 1] = add;
			i = 0;
		}
		else
			i++;
	}
}
