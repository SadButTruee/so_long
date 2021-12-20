/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:38:18 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 18:34:16 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_see_symbol(t_data data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (i <= data.height)
	{
		while (j < data.width)
		{
			c = ft_is_char(data.mas[i][j]);
			if (c == 1)
				j++;
			else
				return (-1);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_see_wall(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data.height)
	{
		while (j < data.width)
		{
			if (data.mas[i][0] != '1' || data.mas[0][j] != '1')
				return (-1);
			if (data.mas[data.height][j] != '1'
				|| data.mas[i][data.width - 1] != '1')
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_see_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data->height)
	{
		while (j < data->width)
		{
			if (ft_see_wall(*data) == -1)
				return (-1);
			if (data->mas[i][j] == 'P')
				data->p++;
			if (data->mas[i][j] == 'C')
				data->c++;
			if (data->mas[i][j] == 'E')
				data->e++;
			if (ft_see_symbol(*data) == -1)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_error(t_data *data)
{
	if (data->width == -1)
		return (-1);
	if (ft_see_map(data) == -1)
		return (-1);
	if (data->p != 1 || data->e != 1 || data->c == 0)
		return (-1);
	return (0);
}

int	ft_map_processing(char *map, t_data *data)
{
	int		fd;
	int		count;
	char	*line;
	int		d;

	count = 0;
	d = 0;
	data->height = ft_height(map);
	data->width = ft_width(map);
	fd = open(map, O_RDONLY, 0);
	data->mas = (char **)malloc(sizeof(char *) * (data->height + 1));
	while (count <= data->height)
	{
		data->mas[count] = ft_g_n_l(fd, &line);
		count++;
	}
	ft_init_image(data);
	d = ft_error(data);
	close(fd);
	return (d);
}
