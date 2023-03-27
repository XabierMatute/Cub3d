/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:10:19 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/25 19:57:34 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	char	*ft_check_str(char *str)
{
	if (str[0])
	{
		return (str);
	}
	else
	{
		free(str);
		return (NULL);
	}
}

char	*ft_get_next_line(int fd)
{
	int		i;
	int		rd;
	char	c[2];
	char	*buf;
	char	*aux;

	rd = 1;
	i = 0;
	buf = (char *)malloc(sizeof(char) * 1);
	buf[0] = '\0';
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		c[rd] = '\0';
		aux = buf;
		buf = ft_strjoin(buf, c);
		free(aux);
		i++;
		if (c[0] == '\n')
			break ;
	}
	if ((!buf[i - 1] && !rd) || rd == -1)
		return (ft_check_str(buf));
	return (buf);
}