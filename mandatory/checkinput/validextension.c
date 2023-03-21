/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validextension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:08:42 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/21 18:15:43 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int		validextension(char *path)
{
	path += ft_strlen(path) - ft_strlen(INPUT_EXTENSION);
	if (ft_strncmp(path, INPUT_EXTENSION, ft_strlen(INPUT_EXTENSION)))
	{
		return (0);
	}
	return (1);
}
