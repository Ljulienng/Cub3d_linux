/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:33:16 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/01 13:10:51 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	define_tex(char *line, t_map *map, char flag)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	flag == 'N' ? map->text_path.no = ft_strdup(line + i) : 0;
	flag == 'S' ? map->text_path.so = ft_strdup(line + i) : 0;
	flag == 'W' ? map->text_path.we = ft_strdup(line + i) : 0;
	flag == 'E' ? map->text_path.ea = ft_strdup(line + i) : 0;
	flag == 's' ? map->text_path.spr = ft_strdup(line + i) : 0;
	flag == 'F' ? convert_rgb(map, line + i, 0) : 0;
	flag == 'C' ? convert_rgb(map, line + i, 1) : 0;
}

static void	define_res(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == 'R')
		i++;
	map->res_x = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	map->res_y = ft_atoi(line + i);
}

static void	define_flag(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	line[i] == 'R' ? define_res(line, map) : 0;
	line[i] == 'N' && line[i + 1] == 'O' ? \
	define_tex(line + i + 2, map, 'N') : 0;
	line[i] == 'S' && line[i + 1] == 'O' ? \
	define_tex(line + i + 2, map, 'S') : 0;
	line[i] == 'W' && line[i + 1] == 'E' ? \
	define_tex(line + i + 2, map, 'W') : 0;
	line[i] == 'E' && line[i + 1] == 'A' ? \
	define_tex(line + i + 2, map, 'E') : 0;
	line[i] == 'S' && line[i + 1] != 'O' ? \
	define_tex(line + i + 1, map, 's') : 0;
	line[i] == 'F' ? define_tex(line + i + 1, map, 'F') : 0;
	line[i] == 'C' ? define_tex(line + i + 1, map, 'C') : 0;
}

static void	init_loop(char *line, t_map *map, char **tmp)
{
	int	i;

	i = 0;
	if (ft_is_set(line[i], FLAGS))
		define_flag(line, map);
	if (map->check_int && (line[0] == '1' || line[0] == ' '))
	{
		while (line[i] && line[i] != '\n')
		{
			if (line[i] == '1' || line[0] == ' ')
				map->x++;
			i++;
		}
		map->check_int--;
	}
	if (line[0] == '1' || line[0] == ' ')
	{
		tmp[map->player.x] = ft_strdup(line);
		map->player.x++;
		map->y++;
	}
}

int			init_map(char *av, t_map *map)
{
	char	*line;
	int		ret;
	int		fd;
	char	**tmp;

	line = NULL;
	map->player.x = 0;
	lst_malloc((void **)&tmp, init_y(map, av) *\
	sizeof(int *), map);
	if (!(fd = open(av, O_RDONLY)))
		return (0);
	while ((ret = get_next_line(fd, &line)))
	{
		init_loop(line, map, tmp);
		ft_strdel(&line);
	}
	if (line[0] == '1' || line[0] == ' ')
	{
		tmp[map->player.x] = ft_strdup(line);
		map->y++;
	}
	ft_strdel(&line);
	close(fd);
	parse_map(map, tmp);
	return (check_map(map));
}
