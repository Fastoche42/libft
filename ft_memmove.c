/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:53:00 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/10 18:48:52 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dt;
	unsigned char	*sc;
	size_t			i;

	if (!n)
		return (dest);
	if (dest == NULL || src == NULL)
		return (NULL);
	dt = (unsigned char *)dest;
	sc = (unsigned char *)src;
	i = -1;
	if (sc < dt)
		while (n--)
			dt[n] = sc[n];
	else
		while (++i < n)
			dt[i] = sc[i];
	return (dest);
}
