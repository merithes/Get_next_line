/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:23:36 by vboivin           #+#    #+#             */
/*   Updated: 2017/03/11 21:51:47 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_join(char *inp1, char *inp2)
{
	char	*outp;

	outp = ft_strjoin(inp1, inp2);
	if (inp1)
		free(inp1);
	return (outp);
}
