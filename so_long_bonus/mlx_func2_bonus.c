/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:02:45 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 18:32:51 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mac(t_data *data)
{
	data->mac = mlx_xpm_file_to_image(data->mlx,
			data->mac_img, &data->i_w, &data->i_h);
	mlx_put_image_to_window(data->mlx, data->window, data->mac, 50, 0);
}

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

void	ft_hach_2(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->hach_2 = mlx_xpm_file_to_image(data->mlx,
			data->hach_2_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		while (j < data->width)
		{
			if (data->mas[i][j] == 'W')
				mlx_put_image_to_window(data->mlx,
					data->window, data->hach_2, j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_block(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->dps = mlx_xpm_file_to_image(data->mlx,
			data->asf_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		while (j < data->width)
		{
			if (data->mas[i][j] == 'W')
				mlx_put_image_to_window(data->mlx,
					data->window, data->dps, j * 50, i * 50);
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_animashion(t_data *data)
{
	data->clock++;
	if (data->done == 0 && data->clock == 4000)
	{
		ft_block(data);
		ft_hach_2(data);
	}
	else if (data->done == 0 && data->clock == 8000)
	{
		ft_block(data);
		ft_hach(data);
		data->clock = 0;
	}
	if (data->done != 0)
		data->dps = mlx_xpm_file_to_image(data->mlx,
				data->asf_img, &data->i_w, &data->i_h);
	return (0);
}
