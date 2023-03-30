/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_coma_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:54:58 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 23:56:40 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	double_coma_error(char *id)
{
	printf("❌Error: en %s hay mas de una coma seguida\n", id);
	return (0);
}
