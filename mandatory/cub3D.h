/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:09:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/31 12:18:37 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

enum {
	R,
	G,
	B,
};

typedef struct s_game{
	void	*no_texture;
	void	*ea_texture;
	void	*so_texture;
	void	*we_texture;
	char	f_color[3];
	char	c_color[3];
	char	**map;
}	t_game;

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
char	*get_raw_data(char *path, char *id);
char	*get_data(char *path, char *id);
char	**get_raw_map(char *path);
char	**get_map(char *path);
int		map_open(char *path);
size_t	map_height(int fd);

/* ------------------- INIT ---------------------*/

/* ------------------- UTILS ---------------------*/
char	*ft_get_next_line(int fd);
void	ft_free2(void **arr);
int		ft_args_lenght(char **args);
int		valid_id(char	*line);
int		is_player(char c);
int		is_void(char c);

/* ------------------- END ---------------------*/

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