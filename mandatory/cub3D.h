/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:09:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/27 14:09:42 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

/* ------------------- CHECKINPUT ---------------------*/
int		validinput(char *path);
int		validextension(char *path);
# define INPUT_EXTENSION ".cub"

int		readable(char *path);
int		have_all_data(char *path);
int		datanum(char *path, char *id);

/* ------------------- PARSE ---------------------*/

/* ------------------- INIT ---------------------*/

/* ------------------- UTILS ---------------------*/
char	*ft_get_next_line(int fd);

/* ------------------- END ---------------------*/

/* ------------------- ERRORS ---------------------*/
int		argc_error(int argc);
int		extension_error(char *path, char *extension);
int		read_error(char *path);
int		format_error(char *path);
int		nodata_error(char *id);
int		missingdata_error(char *path);
int		repeatdata_error(char *path);

#endif