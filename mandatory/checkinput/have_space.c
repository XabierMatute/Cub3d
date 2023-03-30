/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:31:52 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 23:33:38 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	have_space(char *path, char	*id)
{
	char	*data;
	char	c;

	data = get_raw_data(path, id);
	c = data[0];
	free(data);
	return (c == ' ');
}

int	all_have_space(char *path)
{
	if (!have_space(path, "NO"))
		return (nospace_error("NO"));
	if (!have_space(path, "SO"))
		return (nospace_error("SO"));
	if (!have_space(path, "EA"))
		return (nospace_error("EA"));
	if (!have_space(path, "WE"))
		return (nospace_error("WE"));
	if (!have_space(path, "F"))
		return (nospace_error("F"));
	if (!have_space(path, "C"))
		return (nospace_error("C"));
	return (1);
}
