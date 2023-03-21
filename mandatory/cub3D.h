/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:09:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/21 18:35:07 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
# include "./libft/libft.h"

/* ------------------- CHECKINPUT ---------------------*/
int		validinput(char *path);
int		validextension(char *path);
# define	INPUT_EXTENSION ".cub"

int		readable(char *path);

/* ------------------- PARSE ---------------------*/

/* ------------------- INIT ---------------------*/

/* ------------------- UTILS ---------------------*/

/* ------------------- END ---------------------*/

/* ------------------- ERRORS ---------------------*/
int		argc_error(int argc);
int		extension_error(char *path, char *extension);
int		read_error(char *path);

#endif