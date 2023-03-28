/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:35:33 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 13:22:49 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	format_error(char *path)
{
	printf("❌Error: \"%s\" no tiene un formato valido\n", path);
	return (0);
}
