/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:17:56 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 18:34:41 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_game(t_data data)
{
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx,
			data.width * 50, (data.height + 1) * 50, "so_long");
	ft_back(&data);
	ft_konus(&data);
	ft_mazda(&data);
	ft_nevesta(&data);
	ft_hach(&data);
	ft_mac(&data);
	ft_exit(&data);
	mlx_string_put(data.mlx, data.window, 58, 18, 0x000000, "STEPS");
	mlx_string_put(data.mlx, data.window, 71, 28, 0x000000, "0");
	mlx_hook (data.window, 2, 0, ft_key, &data);
	mlx_hook (data.window, 17, 0, ft_key_exit, &data);
	mlx_loop_hook (data.mlx, ft_animashion, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		count;

	if (argc == 2)
	{
		count = 0;
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
		{
			ft_putstr("Error\nMemory allocation error\n");
			return (-1);
		}
		count = ft_map_processing(argv[1], data);
		if (count < 0)
		{
			ft_putstr("Error\nWrong card\n");
			ft_clear_mas(*data);
			free(data);
			return (-1);
		}
		ft_game(*data);
		ft_clear_mas_val(data);
		free(data);
	}
	return (0);
}
