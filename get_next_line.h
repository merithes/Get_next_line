/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:54:14 by vboivin           #+#    #+#             */
/*   Updated: 2017/03/11 22:10:31 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100000000
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(int fd, char **input);

#endif
