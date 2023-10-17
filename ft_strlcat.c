/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:49:37 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/08 19:01:55 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;

	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dest);
	if (!size)
		return (lensrc);
	if (size > lendst)
	{
		while (src[i] && (lendst + i < size - 1))
		{
			dest[lendst + i] = src[i];
			i++;
		}
		dest[lendst + i] = '\0';
	}
	if (size > lendst)
		return (lensrc + lendst);
	return (lensrc + size);
}
