/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validdata_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:44:28 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validdata_error(char *path)
{
	printf("❌Error: \"%s\" tiene datos con formato invalido\n", path);
	return (0);
}
