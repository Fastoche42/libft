/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:35:38 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/10 18:46:38 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	char	*resu;
	char	*strstart;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start > lens)
		len = 0;
	if ((lens < start + 1 + len) && (start <= lens))
		len = (lens - start);
	resu = malloc((len + 1) * sizeof(char));
	if (!resu)
		return (NULL);
	if (!len || !lens || lens < start + 1)
	{
		resu[0] = '\0';
		return (resu);
	}
	strstart = ((char *)s + start);
	ft_strlcpy (resu, strstart, len + 1);
	return (resu);
}
