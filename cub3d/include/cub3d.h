/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:45:47 by mrital-           #+#    #+#             */
/*   Updated: 2024/05/17 13:51:30 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MISSING_IDENTIFIER 404
# define SPACE 32
# define MISSING_MAP 405
# define INVALID_MAP 400
# define WALL 49
# define WINDOW_ERROR 401
# define SUCCESS 1
# define INVALID_PATH 409
# define INVALID_RGB 255
# define TILE_SIZE 35
# define WIDTH 1000
# define HEIGHT 1000
# define PI 3.14159265
# define SPEED 1
# define INT_MAX 2147483647
# define FOV_ANGLE 1.047
# define FALSE 0
# define TRUE 1

# include "../src/get_next_line/get_next_line.h"
# include "../src/libft/libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_map
{
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f_hex;
	char			*f;
	char			*c;
	void			*mlx_ptr;
	void			*mlx_win;
	int				width;
	int				height;
	int				s_r;
	int				s_g;
	int				s_b;
	int				g_r;
	int				g_g;
	int				g_b;
	float			x;
	float			y;
	char			direction;
}					t_map;

typedef struct s_ray
{
	float			ray_angle;
	float			wallhit_x;
	float			wallhit_y;
	float			distance;
	int				hit_vertical;
	float			wall_height;
	float			wall_width;
	mlx_texture_t	*texture;
}					t_ray;

typedef struct s_cast
{
	mlx_texture_t	*texture;
	int				is_up;
	int				is_down;
	int				is_right;
	int				is_left;
	int				foundhorz_hit;
	int				foundvert_hit;
	float			horzhit_x;
	float			horzhit_y;
	float			verthit_x;
	float			verthit_y;
	float			x_inter;
	float			y_inter;
	float			x_step;
	float			y_step;
	float			horznext_x;
	float			horznext_y;
	float			vertnext_x;
	float			vertnext_y;
	float			x_text;
	float			y_text;
}					t_cast;

typedef struct data_s
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*ea;
	mlx_texture_t	*we;
	t_ray			*ray;
	t_map			*map;
	t_cast			cast;
	char			**map_dub;
	float			angle;
	float			x;
	float			y;
	float			t_y;
	float			t_x;
	int				width;
	int				height;
	float			fov;
	char			direction;
	float			wall_h;
	float			wall_bottom;
	float			wall_top;
}					t_data;

//-==================

void				ft_move_left(t_data *data);
void				ft_move_down(t_data *data);
void				ft_move_right(t_data *data);
void				ft_move_up(t_data *data);

void				ft_norm(t_data	*mlx, t_map	*map);
void				draw(t_data *data, t_map *map);
int					generate_color(int r, int g, int b, int a);
float				angle_adjast(float angle, char sign);
float				init_angle(t_map *map);
int					check_wall(t_data *data);
void				setup_angle(float *angle);
int					get_player_position(t_map *m);
void				draw_game(t_data *data);

void				init_variables_ground(t_map *m, char *str, int pos, int i);
void				init_variables_sky(t_map *m, char *str, int pos, int i);
void				init_struct_rgbs(t_map *m, char *str, int index);
void				quit_program(int errid, t_map *m);
char				**realloc_2d(char **tab, char *str);
void				read_file(int fd, t_map *m);
char				*ft_strdup_no_newlines(char *s1);
void				clean_directions(t_map *m);
char				*remove_spaces_id(char *str, t_map *m);
size_t				ft_strlen_from(const char *str, int i);
size_t				ft_strlen_without(const char *str, int pos, char exc);
void				read_map_lines(char **lines, t_map *m);
int					get_map_start_line(char **lines);
char				*remove_char(char *str, char c);
void				check_map(t_map *m);
void				check_lines_width(t_map *m);
size_t				ft_2dlen(char **tab);
int					is_wall(char c);
void				start_game_window(t_map *m, t_data *data);
void				free_2darr(char **tab);
void				init_struct_pointers(t_map *m);
void				check_paths(t_map *m);
void				check_rgbs(t_map *m);
int					check_ranges(char *str);
int					count_commas(char *str);
void				duplicate_map(t_map *m, t_data *data, int w);
void				hook(void *param);
void				vert_inter(t_data *data, float ray_angle);
int					is_twall(t_data *data, float x, float y);
void				horz_inter(t_data *data, float ray_angle);
void				cast_all_rays(t_data *data);
void				cast_ray(t_data *data, int i);
void				calculate_hit(t_data *data, int i);
float				dist_two_points(float x1, float y1, float x2, float y2);
void				check_inv_map_elem(t_map *m);
int					check_elem(char c);
void				check_map_walls(t_map *m);
void				read_file_part2(char **lines, t_map *m);
void				filter_lines(char **lines, t_map *m);
void				init_player_direction(char **lines, t_map *m);

/* ----------  Draw Textures Part ------------ */

int					ft_pxl(int r, int g, int b, int a);
void				set_textures(t_data *data, int i);
void				draw_game_textures(t_data *data);
void				set_x_texture_coord(t_data *data, int i,
						mlx_texture_t *texture);
void				set_y_texture_coord(t_data *data, int start);
int					init_texture_c(float x, float y, mlx_texture_t *texture);
void				draw_texture(t_data *data, int i);

#endif