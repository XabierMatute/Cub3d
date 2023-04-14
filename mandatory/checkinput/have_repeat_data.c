/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_repeat_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:19:09 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	have_repeat_data(char *path)
{
	if (datanum(path, "NO") > 1)
		return (repeat_data_error("NO"));
	if (datanum(path, "SO") > 1)
		return (repeat_data_error("SO"));
	if (datanum(path, "EA") > 1)
		return (repeat_data_error("EA"));
	if (datanum(path, "WE") > 1)
		return (repeat_data_error("WE"));
	if (datanum(path, "F") > 1)
		return (repeat_data_error("F"));
	if (datanum(path, "C") > 1)
		return (repeat_data_error("C"));
	return (1);
}
