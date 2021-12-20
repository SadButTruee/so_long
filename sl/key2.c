/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:48:23 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 19:44:02 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_1_W(t_data *data, int i, int j)
{
	if (data->mas[i][j] != '1')
		return (0);
	else
		return (1);
}

int	ft_is_E(t_data *data, int i, int j)
{
	if (data->mas[i][j] != 'E' && data->is_nev >= 0)
		return (0);
	else if (data->mas[i][j] == 'E' && data->is_nev == 0)
		return (1);
	else
		return (-1);
}

int	ft_step(t_data *data)
{
	data->step++;
	data->step_str = ft_itoa(data->step);
	ft_putstr("step = ");
	ft_putnbr(data->step);
	ft_putstr("\n");
	free(data->step_str);
	return (data->step);
}

void	ft_win(t_data *data)
{
	int	i;
	int	j;

	i = data->width / 2 * 50;
	j = data->height / 2 * 50;
	mlx_put_image_to_window(data->mlx, data->window, data->maz, i, j);
	mlx_string_put(data->mlx, data->window, i, j + 70, 0xFF0000, "YOU WIN");
}
