/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:57:55 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 18:47:09 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_mas(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data.height)
	{
		free(data.mas[i]);
		i++;
	}
	free(data.mas);
}

void	ft_clear_mas_val(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data->height)
	{
		while (j <= data->width)
		{
			free(&data->mas[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_clear(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
