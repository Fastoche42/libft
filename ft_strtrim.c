/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:04:29 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/10 19:08:31 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	if (s1[first])
	{
		last = ft_strlen(s1);
		while (ft_strchr(set, s1[last - 1]))
			last--;
	}
	else
		last = first;
	str = malloc(sizeof(char) * (last - first + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + first, last - first + 1);
	return (str);
}
