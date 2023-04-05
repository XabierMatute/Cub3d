/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:09:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/05 18:23:18 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define WIN_WIDTH			600
# define WIN_HEIGHT			600
# define WIN_TITLE			"CUB3D"

# define WIN_WIDTH			600

# define NORTH				M_PI / 2
# define EAST				NORTH - M_PI / 2
# define WEST				NORTH + M_PI / 2
# define SOUTH				NORTH + M_PI

# define MOVE_SPEED			0.10
# define BASEBOARD			0.10

enum{
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	W_KEY = 13,
	LEFT_KEY = 123,
	RIGHT_KEY = 124,
	ESC_KEY = 53,
};

enum {
	R,
	G,
	B,
};

enum {
	x,
	y,
	angle,
};

typedef struct s_texture{
	void	*image;
	int		dimention[2];
}	t_texture;

typedef struct s_game{
	void		*mlx;
	void		*window;
	t_texture	*no_texture;
	t_texture	*ea_texture;
	t_texture	*so_texture;
	t_texture	*we_texture;
	int			f_color;
	int			c_color;
	char		**map;
	double		player[3];
}	t_game;

int		cubed(t_game	*input);

/* ------------------- CHECKINPUT ---------------------*/
int		validinput(char *path);
int		validextension(char *path);
# define INPUT_EXTENSION ".cub"

int		readable(char *path);
int		datanum(char *path, char *id);
int		have_all_data(char *path);
int		have_repeat_data(char *path);
int		valid_data(char *path);
int		all_have_space(char *path);
int		all_have_data(char *path);
int		all_valid_colors(char *path);
int		are_all_num(char **ss);
int		are_all_inrange(char **ss);
int		strange_id(char	*path);
int		invalidchar_map(char **map);
size_t	players_map(char **map);
int		closed_map(char **map);

/* ------------------- PARSE ---------------------*/
t_game	*parse(char *path);
char	*get_raw_data(char *path, char *id);
char	*get_data(char *path, char *id);
char	**get_raw_map(char *path);
char	**get_map(char *path);
int		map_open(char *path);
size_t	map_height(int fd);
int		get_color(char *path, char *id);

/* ------------------- INIT ---------------------*/
t_game	*initgame(char *path);
t_game	*initgame_mlx(t_game *game);
t_game	*initgame_window(t_game *game);
t_game	*initgame_colors(t_game *game, char *path);
t_game	*initgame_images(t_game *game, char *path);
t_game	*initgame_player(t_game *game, char *path);
t_game	*initgame_map(t_game *game, char *path);

/* ------------------- MOVEMENT ---------------------*/
int		move_forward(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		move_back(t_game *game);
int		move_forward(t_game *game);



/* ------------------- S_CALL ---------------------*/
void	*smalloc(size_t	size);
int		sclose(int	fd);
int		sopen(char	*path, int flag);
ssize_t	sread(int fd, void *buf, size_t b);

/* ------------------- UTILS ---------------------*/
char	*ft_get_next_line(int fd);
void	ft_free2(void **arr);
int		ft_args_lenght(char **args);
int		valid_id(char	*line);
int		is_player(char c);
int		is_void(char c);
void	ft_free(void *p);

/* ------------------- END ---------------------*/
int		endgame(t_game	*game);
void	endgame_images(t_game *game);

/* ------------------- ERRORS ---------------------*/
int		argc_error(int argc);
int		extension_error(char *path, char *extension);
int		read_error(char *path);
int		format_error(char *path);
int		nodata_error(char *id);
int		missingdata_error(char *path);
int		repeat_data_error(char *id);
int		repeat_error(char *path);
int		validdata_error(char *path);
int		strange_error(char *path);
int		nospace_error(char *id);
int		empty_error(char *id);
int		color_error(char *id);
int		color_c_error(int c);
int		double_coma_error(char *id);
int		color_n_error(char *id);
int		color_r_error(char *id);
int		map_error(char *path);
int		map_invalidchar_error(void);
int		players_error(size_t n);
int		map_close_error(void);

#endif