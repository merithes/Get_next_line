/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <vboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:57:20 by vboivin           #+#    #+#             */
/*   Updated: 2017/03/11 22:21:03 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newmem;

	newmem = (char *)malloc(size + 1);
	if (!newmem)
		return (NULL);
	ft_bzero(newmem, size + 1);
	return (newmem);
}
