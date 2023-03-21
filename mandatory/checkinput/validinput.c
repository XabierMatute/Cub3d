/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:51:20 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/21 19:58:09 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	validinput(char *path)
{
	if (!validextension(path))
		return (extension_error(path, INPUT_EXTENSION));
	if (!readable(path))
		return (read_error(path));
	return (0);
}
