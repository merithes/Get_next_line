/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:52:04 by vboivin           #+#    #+#             */
/*   Updated: 2017/01/13 16:38:33 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*str;
	int		fd;
	int fd2;
	int	rez;

	if (ac <= 2)
	{
		printf("ac\n");
		return 0;
	}
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	printf("0a\n");
	rez = get_next_line(fd, &str);
	printf("%s\n", str);
	rez = get_next_line(fd2, &str);
	printf("%s\n", str);
	return 0;
}
