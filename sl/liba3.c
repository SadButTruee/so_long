/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:08:00 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 19:38:37 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_char(char c)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 0;
	str = "PCE10";
	while (str[a])
	{
		if (str[a] == c)
			i++;
		a++;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	long	s;

	s = n;
	if (s < 0)
	{
		ft_putchar('-');
		s *= -1;
	}
	if (s > 9)
		ft_putnbr(s / 10);
	ft_putchar((s % 10) + '0');
}
