/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:15:50 by vboivin           #+#    #+#             */
/*   Updated: 2017/02/02 19:34:57 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*shifter(char *inp, int movr)
{
	char	*outp;
	int		len;

	len = ft_strlen(inp) - ++movr;
	if (len > 0)
	{
		if (!(outp = malloc(len + 1)))
			return (NULL);
		ft_bzero(outp, len);
		if (inp[movr] && outp)
			ft_strcpy(outp, inp + movr);
	}
	else
	{
		if (!(outp = malloc(1)))
			return (NULL);
		outp[0] = 0;
	}
	if (inp)
		free(inp);
	return (outp);
}
