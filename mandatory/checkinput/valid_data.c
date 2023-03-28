/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:09:48 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 13:37:03 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	valid_data(char *path)
{
	if (!all_have_space(path))
		return (0);
	if (!all_have_data(path))
		return (0);
	if (!all_valid_colors(path))
		return (0);
	return(1);
}