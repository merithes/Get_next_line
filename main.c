/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:52:04 by vboivin           #+#    #+#             */
/*   Updated: 2017/01/05 18:07:12 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac == 1)
	{
		printf("ac\n");
		return 0;
	}
	printf("0a\n");
	get_next_line(fd, &str);
	printf("%s\n", str);
	return 0;
}
