/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:56:14 by vboivin           #+#    #+#             */
/*   Updated: 2017/02/02 19:52:21 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_realloc(char *inp, int qty)
{
	char	*outp;
	int		i;

	i = 0;
	if (!(outp = malloc(qty)))
		return (NULL);
	while (inp[i])
	{
		outp[i] = inp[i];
		i++;
	}
	outp[i] = 0;
	free(inp);
	return (outp);
}

int			readit(int fd, char **inp)
{
	char	*bufr;
	char	*outp;
	int		i;
	int		errn;

	i = 0;
	bufr = malloc(BUFF_SIZE);
	if (!(outp = malloc(BUFF_SIZE)) || !(bufr))
		return (-1);
	ft_bzero(outp, BUFF_SIZE);
	while (i >= 0)
	{
		errn = read(fd, bufr, BUFF_SIZE);
		if ((errn == -1)
				|| (i++ != 0 && !(outp = ft_realloc(outp, (i * BUFF_SIZE)))))
			return (-1);
		ft_strncat(outp, bufr, errn);
		ft_bzero(bufr, BUFF_SIZE);
		if (errn < BUFF_SIZE || errn == 0)
			break ;
	}
	free(bufr);
	if (i > 0)
		*inp = outp;
	return (1);
}

long long	ft_charget(char *inp)
{
	long long int	i;

	i = -1;
	if (!(inp))
		return (-1);
	while (inp[++i] != '\0')
		if (inp[i] == '\n')
			return (i);
	return (i);
}

int			cpy(char **dest, char *src, int len)
{
	char	*outp;
	int		i;

	i = 0;
	if (!(outp = ft_strnew(len)))
		return (-1);
	while (i < len)
	{
		outp[i] = src[i];
		i++;
	}
	outp[i] = 0;
	*dest = outp;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static	char	*stokr[MAX_FD_VALUE];
	int				len_line;
	char			*toset;

	if (fd < 0 || fd > MAX_FD_VALUE || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!stokr[fd])
		if (readit(fd, &stokr[fd]) == -1)
			return (-1);
	if ((len_line = ft_charget(stokr[fd])) == -1 || stokr[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	cpy(&toset, stokr[fd], len_line);
	stokr[fd] = shifter(stokr[fd], len_line);
	*line = toset;
	return (1);
}
