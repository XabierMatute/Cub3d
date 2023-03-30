/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:31:52 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 23:33:06 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	have_data(char *path, char	*id)
{
	char	*data;
	char	c;

	data = get_data(path, id);
	c = data[0];
	free(data);
	return (c != '\0' && c != '\n');
}

int	all_have_data(char *path)
{
	if (!have_data(path, "NO"))
		return (empty_error("NO"));
	if (!have_data(path, "SO"))
		return (empty_error("SO"));
	if (!have_data(path, "EA"))
		return (empty_error("EA"));
	if (!have_data(path, "WE"))
		return (empty_error("WE"));
	if (!have_data(path, "F"))
		return (empty_error("F"));
	if (!have_data(path, "C"))
		return (empty_error("C"));
	return (1);
}
