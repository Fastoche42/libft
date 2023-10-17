/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:18:33 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/11 10:13:03 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* return ln AND p =abs(n) */
static int	intlen(int n, unsigned int *p)
{
	int				ln;
	unsigned int	buf;

	ln = 1;
	if (n < 0)
		ln++;
	*p = (unsigned int)(n * ((n > 0) * 2 - 1));
	buf = *p;
	while (buf > 9)
	{
		ln++;
		buf /= 10;
	}
	return (ln);
}

char	*ft_itoa(int n)
{
	unsigned int	p;
	int				ln;
	char			*str;

	ln = intlen(n, &p);
	str = ft_calloc((ln + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (ln--)
	{
		str[ln] = (p % 10) + '0';
		p /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
