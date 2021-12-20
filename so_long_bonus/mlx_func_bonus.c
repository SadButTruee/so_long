/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:53:50 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 18:33:41 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_back(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->asf = mlx_xpm_file_to_image(data->mlx,
			data->asf_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j < data->width)
		{
			mlx_put_image_to_window(data->mlx,
				data->window, data->asf, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_konus(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->kon = mlx_xpm_file_to_image(data->mlx,
			data->kon_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (i == 0 && j == 1)
			{
				j++;
				continue ;
			}
			if (data->mas[i][j] == '1')
				mlx_put_image_to_window(data->mlx,
					data->window, data->kon, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_mazda(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->maz = mlx_xpm_file_to_image(data->mlx,
			data->maz_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		while (j < data->width)
		{
			if (data->mas[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx,
					data->window, data->maz, j * 50, i * 50);
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_nevesta(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->is_nev = data->c;
	data->nev = mlx_xpm_file_to_image(data->mlx,
			data->nev_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->mas[i][j] == 'C')
				mlx_put_image_to_window(data->mlx,
					data->window, data->nev, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	ft_hach(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->dps = mlx_xpm_file_to_image(data->mlx,
			data->dps_img, &data->i_w, &data->i_h);
	while (i <= data->height)
	{
		j = 0;
		while (j <= data->width)
		{
			if (data->mas[i][j] == 'W')
				mlx_put_image_to_window(data->mlx,
					data->window, data->dps, j * 50, i * 50);
			j++;
		}
		i++;
	}
}
