/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_data_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:35:33 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 13:23:11 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	repeat_data_error(char *id)
{
	printf("❌Error: hay mas de un %s\n", id);
	return (0);
}

int	repeat_error(char *path)
{
	printf("❌Error: \"%s\" contiene datos repetidos\n", path);
	return (0);
}
