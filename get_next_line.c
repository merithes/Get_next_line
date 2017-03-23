/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:56:14 by vboivin           #+#    #+#             */
/*   Updated: 2017/03/21 15:10:32 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			assign(char **buf, char **toset, char **preset)
{
	*toset = (!*preset) ? ft_strnew(BUFF_SIZE) : *preset;
	if (!*toset)
		return (-1);
	*buf = ft_strnew(BUFF_SIZE);
	if (!*buf)
		return (-1);
	return (0);
}

static int			readit(int fd, char **inp)
{
	char			*bufr;
	char			*outp;
	int				errn;
	int				i;

	if (assign(&bufr, &outp, inp) == -1)
		return (-1);
	i = 0;
	ft_bzero(bufr, BUFF_SIZE + 1);
	while ((errn = read(fd, bufr, BUFF_SIZE)) != 0)
	{
		if ((errn == -1) || !(outp = free_join(outp, bufr)))
			return (-1);
		if ((strchr_int(bufr, '\n') != 0 &&
			(size_t)strchr_int(bufr, '\n') - 1 != ft_strlen(bufr))
				|| bufr[0] == '\n')
			break ;
		ft_bzero(bufr, BUFF_SIZE + 1);
		i++;
	}
	free(bufr);
	*inp = outp;
	if (errn == 0 && i == 0)
		return (0);
	return (1);
}

static char			*shifter(char *inp, int movr)
{
	char			*outp;
	int				len;

	len = ft_strlen(inp) - ++movr;
	if (len >= 0)
	{
		if (!(outp = ft_strnew(len + 1)))
			return (NULL);
		if (inp[movr] && outp)
			ft_strcpy(outp, inp + movr);
	}
	else
		outp = NULL;
	if (inp)
		free(inp);
	return (outp);
}

int					get_next_line(int fd, char **line)
{
	static	char	*stokr[1337];
	int				len_line;
	char			*outp;
	int				ret;

	len_line = 0;
	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0 ||
			(ret = readit(fd, &stokr[fd])) == -1)
		return (-1);
	if (((ret == 0) && !stokr[fd]) || !stokr[fd][0])
	{
		if (stokr[fd])
			ft_memdel((void **)&stokr[fd]);
		*line = NULL;
		return (0);
	}
	if (!(len_line = strchr_int(stokr[fd], '\n')))
		len_line = ft_strlen(stokr[fd]) + 1;
	if (!(outp = ft_strnew(len_line)))
		return (-1);
	ft_strncpy(outp, stokr[fd], len_line - 1);
	stokr[fd] = shifter(stokr[fd], len_line - 1);
	*line = outp;
	return (1);
}
