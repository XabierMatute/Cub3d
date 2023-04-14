/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:59:48 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:12:16 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	printf("%s: %s\n", id, data);
	if (double_coma(data))
		return (free(data), double_coma_error(id));
	if (data[0] == ',' || data[ft_strlen(data) - 1] == ',')
		return (free(data), printf("❌Error: hay alguna coma suelta\n"), 0);
	color = ft_split(data, ',');
	free(data);
	c = ft_args_len(color);
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
