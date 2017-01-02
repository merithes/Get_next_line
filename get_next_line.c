/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:58 by vboivin           #+#    #+#             */
/*   Updated: 2017/01/02 19:24:48 by vboivin          ###   ########.fr       */
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

int		getchr(int fd)
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
		return (667);
	if (bufchr== -1)
		return (666);
	outp = buffed[bufpos++];
	bufchr--;
	return (outp);
}

int		get_next_line(int fd, char **line)
{
	int		a;
	char	*outp;
	int		i;
	
	if (!(outp = malloc(BUFF_SIZE + 1)) || BUFF_SIZE == 0 || fd < 0)
		return (-1);
	i = 0;
	if ((a = getchr(fd)) == 666 || a == 667)
		return (a == 667) ? -1 : 0;
	while (a != '\n' && a != 0)
	{
		outp[i++] = (char)a;
		if (BUFF_SIZE != 0 && (i % BUFF_SIZE) == 0)
		{
			if (!(outp = ft_realloc(outp, (BUFF_SIZE + i))))
				return (-1);
		}
		if ((a = (char)getchr(fd)) == 667)
			return (0);
	}
	outp[i] = '\0';
	printf("%s\n", outp);
	*line = outp;
	return (1);
}
