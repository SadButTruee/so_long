/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:47:48 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 18:34:02 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_height(char *map)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(map, O_RDONLY, 0);
	while (ft_gnl(fd, &line) > 0)
	{
		free(line);
		height++;
	}
	close(fd);
	free(line);
	return (height);
}

int	ft_width(char *map)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map, O_RDONLY, 0);
	ft_gnl(fd, &line);
	width = ft_strlen(line);
	free(line);
	while (ft_gnl(fd, &line) > 0)
	{
		if (ft_strlen(line) != width)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	if (ft_strlen(line) != width)
	{
		free(line);
		return (-1);
	}
	close(fd);
	free(line);
	return (width);
}

void	ft_init_image(t_data *data)
{
	data->step = 0;
	data->done = 0;
	data->p = 0;
	data->c = 0;
	data->e = 0;
	data->asf_img = "sprite/asfalt.xpm";
	data->maz_img = "sprite/mazda.xpm";
	data->dps_img = "sprite/hach.xpm";
	data->kon_img = "sprite/konus.xpm";
	data->mac_img = "sprite/mac.xpm";
	data->gor_img = "sprite/gor.xpm";
	data->nev_img = "sprite/nevesta.xpm";
	data->hach_2_img = "sprite/hach_2.xpm";
}

int	ft_key_exit(t_data *data)
{
	(void)data;
	exit (0);
}
