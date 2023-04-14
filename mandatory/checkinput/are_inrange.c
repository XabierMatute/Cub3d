/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_inrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:50:04 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	are_inrange(char *s)
{
	if (ft_strlen(s) > 3 || ft_atoi(s) > 255)
		return (printf("%s es mayor que 255\n", s), 0);
	return (1);
}

int	are_all_inrange(char **ss)
{
	while (*ss)
	{
		if (!are_inrange(*ss))
			return (0);
		ss++;
	}
	return (1);
}
