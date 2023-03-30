/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_all_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:19:09 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 23:32:47 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	have_all_data(char *path)
{
	if (!datanum(path, "NO"))
		return (nodata_error("NO"));
	if (!datanum(path, "SO"))
		return (nodata_error("SO"));
	if (!datanum(path, "EA"))
		return (nodata_error("EA"));
	if (!datanum(path, "WE"))
		return (nodata_error("WE"));
	if (!datanum(path, "F"))
		return (nodata_error("F"));
	if (!datanum(path, "C"))
		return (nodata_error("C"));
	return (1);
}
