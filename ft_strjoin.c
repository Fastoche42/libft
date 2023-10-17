/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:43:24 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/10 18:51:53 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*resu;
	size_t	i;

	lens1 = ft_strlen (s1);
	lens2 = ft_strlen (s2);
	if (!s1 || !s2)
		return (NULL);
	resu = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!resu)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		resu[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= lens2)
	{
		resu[i + lens1] = s2[i];
		i++;
	}
	return (resu);
}
