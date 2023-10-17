/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:50:27 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/08 18:50:40 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	p;

	if (n < 0)
		ft_putchar_fd('-', fd);
	p = ((2 * (n > 0) - 1) * n);
	if (p > 9)
		ft_putnbr_fd(p / 10, fd);
	ft_putchar_fd(p % 10 + '0', fd);
}
