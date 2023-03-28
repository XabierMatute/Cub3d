/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:50:04 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 17:27:56 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	are_num(char *s)
{
	while(*s)
	{
		if (!ft_isdigit(*s))
			return (printf("\'%c\' no es un digito\n", *s), 0);
		s++;
	}
	return(1);
}

int	are_all_num(char **ss)
{
	while(*ss)
	{
		if (!are_num(*ss))
			return (printf("\"%s\" no es numerico\n", *ss), 0);
		ss++;
	}
	return(1);
}