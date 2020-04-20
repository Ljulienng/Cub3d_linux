/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:33:33 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/02 13:02:44 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		setup_mlx(t_map *map)
{
	if (!(map->win.mlx_ptr = mlx_init()))
		return (0);
	if (!(map->win.mlx_win = mlx_new_window(map->win.mlx_ptr,\
		map->res_x, map->res_y, "Cub3D")))
		return (0);
}

static void		init(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->res_x = 0;
	map->res_y = 0;
	map->check_int = 1;
	map->has_pos = 0;
	map->player.dir_x = -1.0;
	map->player.dir_y = 0;
	map->player.pos_x = 0;
	map->player.pos_y = 0;
	map->player.plane_x = 0;
	map->player.plane_y = 0.66;
	map->texture[0].img = NULL;
	map->texture[1].img = NULL;
	map->texture[2].img = NULL;
	map->texture[3].img = NULL;
	map->texture[4].img = NULL;
	map->player.hit = 0;
	map->player.perpwall = 0;
	map->key = 0;
	map->sprite_nb = 0;
}

static int		main2(int ac, char **av, t_map *map)
{
	if (ac == 2)
		main_game(map, 0);
	if (ac == 3 && !ft_strncmp(av[2], "--save", 7))
	{
		map = ft_calloc(1, sizeof(t_map));
		init(map);
		init_map(av[1], map);
		setup_mlx(map);
		map->win.mlx_img = mlx_new_image(map->win.mlx_ptr,\
		map->res_x, map->res_y);
		if (!(map->win.str = (unsigned int *)mlx_get_data_addr(\
		map->win.mlx_img, &map->win.b_p, &map->win.s_l, &map->win.endian)))
			error_exit(map, 2);
		main_game(map, 1);
		export_as_bmp("screenshot.bmp", (char *)map->win.str,
			map->res_x, map->res_y);
		error_exit(map, 0);
	}
	else if (ac == 3)
		ft_putstr_fd("Error: bad argument\n", 2);
	return (0);
}

static void		start_game(t_map *map, char **av, int ac)
{
	map = ft_calloc(1, sizeof(t_map));
	init(map);
	init_map(av[1], map);
	setup_mlx(map);
	main2(ac, av, map);
}

int				main(int ac, char **av)
{
	t_map	*map;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (av[1][j] != '.')
		j++;
	if (ac == 2 && !ft_strncmp(av[1] + j, ".cub", 4))
		start_game(map, av, ac);
	else if (ac == 3 && !ft_strncmp(av[1] + j, ".cub", 4))
		main2(ac, av, map);
	else if (ac > 3)
		ft_putstr_fd("Error: Too much arguments\n", 2);
	else if (ft_strncmp(av[1] + j, ".cub", 4))
		ft_putstr_fd("Error: File must be .cub\n", 2);
	else
		ft_putstr_fd("Error: File missing\n", 2);
	return (0);
}
