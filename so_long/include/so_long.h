/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:38 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/07 13:23:36 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_TAB 9999
# define IH 75
# define IW 75
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"
# include "../src/get_next_line/get_next_line.h"

typedef struct so_long
{
	int		fd;
	size_t	line_size;
	char	**map_lines;
	char	**all_lines;
	char	**l_cpe;
	char	*comp;
	size_t	tab_size;
	void	*mlx_ptr;
	void	*mlx_win;
	int		player_y;
	int		player_x;
	int		key;
	int		score;
	int		total_score;
	int		move_counter;
	void	*backg;
	void	*player;
	void	*wall;
	void	*exit;
	void	*coll;
}	t_map;

void	reading(char *file_name, t_map *m);
void	read_map(char *file, t_map *m);
int		check_file(char *file, t_map *m);
int		check_ext(char *file);
void	get_lines(t_map *m);
int		check_map(t_map *m);
int		check_line(char *str);
int		check_line_lenght(char *str, t_map *m);
int		must_contain(t_map *m);
int		check_wall_rect(t_map *m);
char	**so_long_split(char *str, char c);
int		ft_word_cnt(char *str, char c);
int		so_long_split_2(char **res, char *str, char c);
int		word_len(char *str, char c);
void	so_long_join(char *dest, char *src, char c, int pos);
char	*put_all_in_one(char **line, t_map *p);
size_t	table_size_counter(t_map *m);
char	**copie_map(t_map *m);
int		check_valid_path(t_map *m);
int		check(t_map *m, size_t x, size_t y);
void	fill_empty(t_map *m, size_t x, size_t y);
void	start_window(t_map *m);
int		init_element(t_map *m);
void	put_elements(t_map *m);
void	put_image_to_window(t_map *m, char e, int x, int y);
int		key_press(int key, t_map *m);
void	move_player(int pos, t_map *m);
void	get_player_position(t_map *m);
int		check_elements(t_map *m, int pos);
int		check_exit(t_map *m, char elem);
void	move_p_down(t_map *m);
void	move_p_up(t_map *m);
void	move_p_right(t_map *m);
void	move_p_left(t_map *m);
void	score_counter(t_map *m, char elem);
void	move_counter(t_map *m);
int		quit_game(t_map *m, int s);

#endif
