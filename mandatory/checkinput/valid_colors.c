/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:59:48 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 13:21:21 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int	valid_colors(char *path, char	*id)
// {
// 	char	*data;
// 	char	**color;
// 	size_t	c;
	
// 	data = get_data(path, id);
// 	color = ft_split(data, ',');
// 	free(data);
// 	c = ft_args_lenght(color);
// 	if (c != 3)//en otra funcion?
// 		return (ft_free2((void **)color), color_c_error(c));
// 	if (!are_all_num(color))
// 		return (ft_free2((void **)color), color_nonum_error(ft_args_lenght(color)));
// 	// if (!are_all_inrange(color))
// 	// 	return (ft_free2((void **)color), color_range_error(ft_args_lenght(color)));
// 	return (ft_free2((void **)color), 1);
// }

int	all_valid_colors(char *path)
{
	// if (!valid_colors(path, "F"))
	// 	return (color_error("F"));
	// if (!valid_colors(path, "C"))
	// 	return (color_error("C"));
	return(1);
}