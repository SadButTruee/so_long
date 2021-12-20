/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:02:45 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 19:48:40 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->gor = mlx_xpm_file_to_image(data->mlx,
			data->gor_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j <= data->width)
		{
			if (data->mas[i][j] == 'E')
				mlx_put_image_to_window(data->mlx,
					data->window, data->gor, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
