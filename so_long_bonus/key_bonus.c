/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:36:43 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 20:16:17 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_key_A(t_data *data, int j, int i)
{
	if (ft_is_1_W(data, i, j - 1) == 0 && ft_is_E(data, i, j - 1) == 0)
		ft_go_left(data, i, j);
	else if (ft_is_1_W(data, i, j - 1) == 0 && ft_is_E(data, i, j - 1) == 1)
	{
		data->step = ft_step(data);
		ft_back(data);
		ft_win(data);
		data->done++;
	}
	else if (data->mas[i][j - 1] == 'W')
		ft_go_game_over(data);
}

void	ft_key_D(t_data *data, int j, int i)
{
	if (ft_is_1_W(data, i, j + 1) == 0 && ft_is_E(data, i, j + 1) == 0)
		ft_go_right(data, i, j);
	else if (ft_is_1_W(data, i, j + 1) == 0 && ft_is_E(data, i, j + 1) == 1)
	{
		data->step = ft_step(data);
		ft_back(data);
		ft_win(data);
		data->done++;
	}
	else if (data->mas[i][j + 1] == 'W')
		ft_go_game_over(data);
}

void	ft_key_W(t_data *data, int j, int i)
{
	if (ft_is_1_W(data, i - 1, j) == 0 && ft_is_E(data, i - 1, j) == 0)
		ft_go_up(data, i, j);
	else if (ft_is_1_W(data, i - 1, j) == 0 && ft_is_E(data, i - 1, j) == 1)
	{
		data->step = ft_step(data);
		ft_back(data);
		ft_win(data);
		data->done++;
	}
	else if (data->mas[i - 1][j] == 'W')
		ft_go_game_over(data);
}

void	ft_key_S(t_data *data, int j, int i)
{
	if (ft_is_1_W(data, i + 1, j) == 0 && ft_is_E(data, i + 1, j) == 0)
		ft_go_down(data, i, j);
	else if (ft_is_1_W(data, i + 1, j) == 0 && ft_is_E(data, i + 1, j) == 1)
	{
		data->step = ft_step(data);
		ft_back(data);
		ft_win(data);
		data->done++;
	}
	else if (data->mas[i + 1][j] == 'W')
		ft_go_game_over(data);
}

int	ft_key(int keycode, t_data *data)
{
	int	i;
	int	j;

	j = data->player_x;
	i = data->player_y;
	if (keycode == 53)
		exit (0);
	if (keycode == 0 && data->done == 0)
		ft_key_A(data, j, i);
	if (keycode == 2 && data->done == 0)
		ft_key_D(data, j, i);
	if (keycode == 13 && data->done == 0)
		ft_key_W(data, j, i);
	if (keycode == 1 && data->done == 0)
		ft_key_S(data, j, i);
	return (0);
}
