/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:40:47 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/08 19:04:02 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *s, size_t n)
{
	size_t	lens;
	size_t	lenstr;
	size_t	i;

	lens = ft_strlen(s);
	lenstr = ft_strlen(str);
	if (!lens || s == NULL)
		return ((char *)str);
	if (n > lenstr)
		n = lenstr;
	i = 0;
	while (i + lens <= n)
	{
		if (!(ft_strncmp(&str[i], s, lens)))
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
