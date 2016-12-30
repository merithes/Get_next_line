/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:58 by vboivin           #+#    #+#             */
/*   Updated: 2016/12/30 15:24:53 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *inp, int toalloc)
{
	char	*outp;
	int		i;

	i = -1;
	if (!(outp = malloc(toalloc + 1)))
		return NULL;
	while (inp[++i])
		outp[i] = inp[i];
	free(inp);
	return (outp);
}

char	getchr(int fd)
{
	static int	bufchr = 0;
	static char	*buffed;
	static int	bufpos = 0;
	char		outp;

	if (bufchr == 0)
	{
		bufpos = 0;
		buffed = malloc(BUFF_SIZE + 1);
		bufchr = read(fd, buffed, BUFF_SIZE);
	}
	if (bufchr == 0)
		return (0);
	outp = buffed[bufpos++];
	bufchr--;
	return (outp);
}

int		get_next_line(int fd, char **line)
{
	char	a;
	char	*outp;
	int		i;
	
	if (!(outp = malloc(BUFF_SIZE + 1)) || BUFF_SIZE == 0)
		return (-1);
	i = 0;
	a = getchr(fd);
	while (a != '\n' && a != '\0')
	{
		outp[i++] = a;
		if (BUFF_SIZE != 0 && (i % BUFF_SIZE) == 0)
			if (!(outp = ft_realloc(outp, (BUFF_SIZE + i))))
				return -1;
		a = getchr(fd);
	}
	outp[i] = '\0';
	*line = outp;
	return (a == '\0')? 0 : 1;
}
