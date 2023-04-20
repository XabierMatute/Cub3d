/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:58:32 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/20 19:59:40 by jperez           ###   ########.fr       */
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

# define WIN_WIDTH			1200
# define WIN_HEIGHT			600
# define WIN_TITLE			"CUB3D"

# define NORTH				M_PI_2		

# define ROTATE_SPEED		1.57079632679489661923132169163975144 / 4
# define MOVE_SPEED			0.5
# define BASEBOARD			0.10

# define MM_TILE_SIZE		2

enum{
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	Q_KEY = 12,
	W_KEY = 13,
	LEFT_KEY = 123,
	RIGHT_KEY = 124,
	DOWN_KEY = 125,
	UP_KEY = 126,
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

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     height;
    int     width;
}   t_img;

typedef struct s_game{
	void		*mlx;
	void		*window;
	t_img		*no_texture;
	t_img		*ea_texture;
	t_img		*so_texture;
	t_img		*we_texture;
	int			floor_color;
	int			ceiling_color;
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
t_img	*unify(void *mlx, t_img *texture);
t_img	*mirror_unify(void *mlx, t_img *texture);

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
int		look_left(t_game *game);
int		look_right(t_game *game);

/* ------------------- S_CALL ---------------------*/
void	*smalloc(size_t	size);
int		sclose(int fd);
int		sopen(char	*path, int flag);
ssize_t	sread(int fd, void *buf, size_t b);

/* ------------------- UTILS ---------------------*/
char	*ft_get_next_line(int fd);
void	ft_free2(void **arr);
int		ft_args_len(char **args);
int		valid_id(char	*line);
int		is_player(char c);
int		is_void(char c);
void	ft_free(void *p);

/* ------------------- END ---------------------*/
int		endgame(t_game	*game);
void	endgame_images(t_game *game);
void	free_texture(t_img	*texture);

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


// # define WIN_WIDTH			1200
// # define WIN_HEIGHT			600
# define UNIT					64
// # define MOVE_SPEED			25
// # define ANGLE_SPEED		M_PI / 10
# define FOV				M_PI / 3
# define FOV_2				FOV / 2
# define SCREEN_DISTANCE	(WIN_WIDTH / 2) / tan(FOV / 2)
# define ANGLE_GAP			FOV / WIN_WIDTH

# define M_PI_3_2			3 * M_PI_2

# include "mlx/mlx.h" 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./cub3d.h"


// enum{
//     A_KEY = 0,
//     S_KEY = 1,
//     D_KEY = 2,
//     W_KEY = 13,
//     LEFT_KEY = 123,
//     RIGHT_KEY = 124,
//     ESC_KEY = 153,
// };

enum
{
	HORIZONTAL, VERTICAL,
};

// enum {
// 	x,
// 	y,
// 	angle,
// };

typedef struct s_colision
{
	double	colision_x;
	double	colision_y;
	double	distance;
	int		orientation;
}	t_colision;

// typedef struct s_img
// {
// 	void	*mlx_img;
// 	char	*addr;
// 	int		bpp; /* bits per pixel */
// 	int		line_len;
// 	int		endian;
// 	int		height;
// 	int		width;
// }	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	double	player_x;
	double	player_y;
	double	angle;
	int		sky;
	int		floor;
	t_img	*wall;
}	t_mlx;

// typedef struct s_game{
// 	void		*mlx;
// 	void		*window;
// 	t_img	*no_texture;
// 	t_img	*ea_texture;
// 	t_img	*so_texture;
// 	t_img	*we_texture;
// 	int			floor_color;
// 	int			ceiling_color;
// 	char		**map;
// 	double		player[3];
// }	t_game;

int	ft_get_quadrant(double angle);
/*===============================================================================*/
/*									UTILS										 */
/*===============================================================================*/

/* ------------------------------- ft_manage_imgs -------------------------------*/
t_img *ft_create_img(void *mlx, int width, int height);
void	ft_edit_img(t_img *img, t_game *game, int x, int wall_height);
void	ft_create_background(t_img *img, int floor, int sky);
t_img	*ft_save_xpm(t_game *game, char *path);

/* ------------------------------- ft_create_minimap -------------------------------*/
void	ft_create_minimap(void *mlx, void *mlx_win, int width, int height);

/* ------------------------------- ft_print_map -------------------------------*/
void	ft_print_map(char **map);

/* ------------------------------- ft_save_map -------------------------------*/
char	*ft_get_next_line(int fd);
char	**ft_save_map(char *map_addr);

/* ------------------------------- ft_save_map -------------------------------*/
int	ft_args_len(char **args);

/* ------------------------------- ft_save_map -------------------------------*/
int	ft_round_number(double number);

/*===============================================================================*/
/*									RAYCASTING									 */
/*===============================================================================*/

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_horizontal_colisions(double player_x, double player_y,  double angle, char **map);
double	ft_vertical_colisions(double player_x, double player_y,  double angle, char **map);
double	ft_y_colisions(double player_x, double player_y,  double angle, char **map);
double	ft_x_colisions(double player_x, double player_y,  double angle, char **map);

/* ------------------------------- ft_create_minimap -------------------------------*/
void	ft_assing_y_variable(double player_y, double angle, double *ray_gap_y, double *ray_y);
void	ft_assing_x_variable(double player_x, double angle, double *ray_gap_x, double *ray_x);

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_return_min(double horizontal_colision, double vertical_colision);
t_colision	*ft_raycasting(double player_x, double player_y, double angle, char **map);
double	ft_first_quadrant(double player_x, double player_y, double angle, char **map);
double	ft_second_quadrant(double player_x, double player_y, double angle, char **map);
double	ft_third_quadrant(double player_x, double player_y, double angle, char **map);
double	ft_third_quadrant(double player_x, double player_y, double angle, char **map);

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_get_distance(double player_x, double player_y, double ray_x, double ray_y);
int	ft_angle_in_range(double start, double end, double angle);


int	ft_check_horizontal_walls(char **map, double ray_x, double ray_y, double angle);
int	ft_check_vertical_walls(char **map, double ray_x, double ray_y, double angle);

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_normalize_angle(double angle);

/*===============================================================================*/
/*									PAINTING									 */
/*===============================================================================*/

void	ft_calculate_viewport(double angle, double *min_angle, double *max_angle);
double	ft_calculate_wall_height(double ray_distance);
void	ft_paint_column(t_game *game, t_img *img, int x, double max_angle);
void	ft_lightning_gun(char **map, double angle, t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int 	ft_get_texture_pixel(t_img *img, int x, int y);
t_img	*ft_create_img(void *mlx, int width, int height);
void	ft_paint_ceiling(t_img *img, int img_x, double wall_height, int sky_color);
void	ft_paint_floor(t_img *img, int img_x, double wall_height, int floor_color);
void	ft_paint_wall(t_img *img, t_img *texture, int indexes[], double wall_height);

/*===============================================================================*/
/*									PAINTING									 */
/*===============================================================================*/

int	key_hook(int keycode, t_game *game);
int	ft_main_loop(t_game *game);
int	ft_get_texture_x(double player_x, double player_y,  double angle, char **map);
int	ft_get_texture_y(double player_x, double player_y,  double angle, char **map);

#endif
