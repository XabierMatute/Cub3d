/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:06:05 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 22:14:30 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	printmap(char **args)
{
	int	i;

	i = 0;
	if (args)
		while (args[i])
		{
			printf("%i: %s\n", i, args[i]);
			i++;
		}
			printf("%i: %s\n", i, args[i]);
	
	return (i);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (argc_error(argc));
	if (!validinput(argv[1]))
		return (1);
	// return (cub3d(parse(argv[1])));
	return (0);
}
