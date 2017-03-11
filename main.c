/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:52:04 by vboivin           #+#    #+#             */
/*   Updated: 2017/03/11 22:07:20 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*str;
	int		fd;
	int	rez;

	ac++;
	fd = open(av[1], O_RDONLY);
	rez = get_next_line(fd, &str);
	printf("%s:%d\n", str, rez);
	return 0;
}
