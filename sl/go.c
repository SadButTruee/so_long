/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:09:08 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 19:49:19 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_go_left(t_data *data, int i, int j)
{
	data->step = ft_step(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->asf, j * 50 - 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->asf, j * 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->maz, j * 50 - 50, i * 50);
	data->player_x = j - 1;
	data->player_y = i;
	if (data->mas[i][j - 1] == 'C' && data->is_nev > 0)
	{
		data->is_nev--;
		data->mas[i][j - 1] = '0';
	}
}

void	ft_go_right(t_data *data, int i, int j)
{
	data->step = ft_step(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->asf, j * 50 + 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->asf, j * 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->maz, j * 50 + 50, i * 50);
	data->player_x = j + 1;
	data->player_y = i;
	if (data->mas[i][j + 1] == 'C' && data->is_nev > 0)
	{
		data->is_nev--;
		data->mas[i][j + 1] = '0';
	}
}

void	ft_go_up(t_data *data, int i, int j)
{
	data->step = ft_step(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->asf, j * 50, i * 50 - 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->asf, j * 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->maz, j * 50, i * 50 - 50);
	data->player_x = j;
	data->player_y = i - 1;
	if (data->mas[i - 1][j] == 'C' && data->is_nev > 0)
	{
		data->is_nev--;
		data->mas[i - 1][j] = '0';
	}
}

void	ft_go_down(t_data *data, int i, int j)
{
	data->step = ft_step(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->maz, j * 50, i * 50 + 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->asf, j * 50, i * 50);
	mlx_put_image_to_window(data->mlx,
		data->window, data->maz, j * 50, i * 50 + 50);
	data->player_x = j;
	data->player_y = i + 1;
	if (data->mas[i + 1][j] == 'C' && data->is_nev > 0)
	{
		data->is_nev--;
		data->mas[i + 1][j] = '0';
	}
}
