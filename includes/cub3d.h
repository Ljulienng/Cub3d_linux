/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:32:59 by jnguyen           #+#    #+#             */
/*   Updated: 2020/04/02 13:06:59 by julienngy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "mlx.h"

# define FLAGS "RNSWEFC"
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define SPRITE 4

# define KEY_W 1
# define KEY_S 2
# define KEY_A 4
# define KEY_D 8
# define KEY_LEFT 16
# define KEY_RIGHT 256
# define KEY_ESC 65536

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			distance;
	double			invdet;
	double			spritex;
	double			spritey;
	double			transformx;
	double			transformy;
	int				sprite_h;
	int				sprite_w;
	int				spritescreenx;
	int				draws_y;
	int				drawe_y;
	int				draws_x;
	int				drawe_x;
	int				map_x;
	int				map_y;
}					t_sprite;

typedef struct		s_texture
{
	void			*img_ptr;
	unsigned int	*img;
	int				height;
	int				width;
	int				s_l;
	int				b_p_p;
	int				endian;
}					t_texture;

typedef struct		s_text_path
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*spr;
}					t_text_path;

typedef struct		s_player
{
	int				direction;
	int				hit;
	int				side;
	int				x;
	int				stepx;
	int				stepy;
	int				lheight;
	int				draws;
	int				rdraws;
	int				drawe;
	double			wallx;
	double			perpwall;
	double			camerax;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			ray_x;
	double			ray_y;
	double			plane_x;
	double			plane_y;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
}					t_player;

typedef	struct		s_win
{
	void			*mlx_img;
	void			*mlx_ptr;
	void			*mlx_win;
	unsigned int	*str;
	int				b_p;
	int				s_l;
	int				endian;
}					t_win;

typedef struct		s_map
{
	int				**map;
	int				x;
	int				y;
	int				i;
	int				textx;
	int				res_x;
	int				res_y;
	int				map_x;
	int				map_y;
	int				check_int;
	int				has_pos;
	int				floor;
	int				ceiling;
	int				key;
	int				sprite_nb;
	double			*zbuffer;
	t_sprite		**sprite;
	t_text_path		text_path;
	t_texture		texture[5];
	t_player		player;
	t_win			win;
	t_list			*trash;
	t_list			*map_tmp;
}					t_map;

int					init_map(char *av, t_map *map);
int					parse_map(t_map *map, char **tmp);
int					ft_validarg(char c, t_map *map);
int					ft_is_set(char c, char *str);
void				lst_malloc(void **to_malloc, size_t size, t_map *map);
int					check_map(t_map *map);
int					error_exit(t_map *map, int nb);
void				dimain_game(t_map *map);
void				init_pos(t_map *map);
int					init_y(t_map *map, char *av);
void				main_game(t_map *map, int screen);
int					init_tex(t_map *map);
void				init_img(t_map *map);
void				draw_img(t_map *map);
void				sky_floor(t_map *map);
void				convert_rgb(t_map *map, char *line, int fc);
int					close_cross(void *param);
int					key_p(int keycode, t_map *param);
int					key_r(int keycode, t_map *map);
void				moves(t_map *map);
void				move_forward(t_map *map);
void				move_backward(t_map *map);
void				strafe_left(t_map *map);
void				strafe_right(t_map *map);
void				rot_right(t_map *map);
void				rot_left(t_map *map);
void				store_sprite(t_map *map);
void				sort_sprite(t_map *map);
void				sprite_loop(t_map *map);
void				update_sprite(t_map *map);
void				save_bmp(t_map *map);
void				check_spaces(t_map *map, char **tmp);
void				loop_sprites(t_map *map, int i);
void				init_sprites(t_map *map);

#endif
