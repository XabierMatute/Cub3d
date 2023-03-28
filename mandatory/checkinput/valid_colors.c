/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:59:48 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 17:39:17 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	double_coma(char *s)
{
	while (*s)
	{
		if (*s == ',')
			if (s[1] == ',')
				return (1);
		s++;
	}
	return (0);
}

int	valid_colors(char *path, char	*id)
{
	char	*data;
	char	**color;
	size_t	c;

	data = get_data(path, id);
	if (double_coma(data))
		return (free(data), double_coma_error(id));
	color = ft_split(data, ',');
	free(data);
	c = ft_args_lenght(color);
	if (c != 3)
		return (ft_free2((void **)color), color_c_error(c));
	if (!are_all_num(color))
		return (ft_free2((void **)color), color_n_error(id));
	if (!are_all_inrange(color))
		return (ft_free2((void **)color), color_r_error(id));
	return (ft_free2((void **)color), 1);
}

int	all_valid_colors(char *path)
{
	if (!valid_colors(path, "F"))
		return (color_error("F"));
	if (!valid_colors(path, "C"))
		return (color_error("C"));
	return (1);
}
