/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:13:19 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/11 11:33:17 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* LLONG_MAX: 9223372036854775807 */
/* LLONG_MIN: -9223372036854775808 */

static int	ft_checklimit(unsigned long long i, int sig, char u)
{
	unsigned long long	maxdivten;
	int					unit;

	maxdivten = LLONG_MAX / 10;
	if (i < maxdivten)
		return (0);
	else if (i > maxdivten)
		return (1);
	else
	{
		unit = (LLONG_MAX % 10 + (sig - 1) / -2);
		if (u - '0' > unit)
			return (1);
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	unsigned long long	i;
	int					sig;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sig = 1;
	if (*str == '-')
		sig = -1;
	if (*str == '-' || *str == '+')
		str++;
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (ft_checklimit(i, sig, *str))
			return ((sig + 1) / -2);
		i = i * 10 + *str - '0';
		str++;
	}
	return (i * sig);
}
