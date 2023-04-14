/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missingdata_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:35:33 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	nodata_error(char *id)
{
	printf("❌Error: no se encuentra %s\n", id);
	return (0);
}

int	missingdata_error(char *path)
{
	printf("❌Error: \"%s\" no contiene todos los datos\n", path);
	return (0);
}
