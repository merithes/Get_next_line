/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:58 by vboivin           #+#    #+#             */
/*   Updated: 2017/01/13 16:38:35 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *inp, int toalloc)
{
	char	*outp;
	int		i;

	i = -1;
	if (!(outp = malloc(toalloc + 1)))
		return (NULL);
	while (inp[++i])
		outp[i] = inp[i];
	free(inp);
	return (outp);
}

int		getchr(int fd, char *a)
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
	if (bufchr == -1)
		return (-1);
	outp = buffed[bufpos++];
	*a = outp;
	bufchr--;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char	a;
	int		errn;
	char	*outp;
	int		i;

	outp = malloc(BUFF_SIZE + 1);
	if (outp == NULL || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	i = 0;
	errn = getchr(fd, &a);
	if (errn == -1 || errn == 0)
		return (errn == -1) ? -1 : 0;
	while (a != '\n' && a != '\0')
	{
		outp[i++] = a;
		if (BUFF_SIZE != 0 && (i % BUFF_SIZE) == 0)
			if (!(outp = ft_realloc(outp, (BUFF_SIZE + i))))
				return (-1);
		if (!(getchr(fd, &a)))
			break ;
	}
	outp[i] = '\0';
	*line = outp;
	return (1);
}
