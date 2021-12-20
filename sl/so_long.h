/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:18:23 by rtracee           #+#    #+#             */
/*   Updated: 2021/11/29 19:47:34 by rtracee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>

# define UC unsigned char

typedef struct s_data
{
	int		height;
	int		width;
	char	**mas;
	int		i_w;
	int		i_h;
	int		player_x;
	int		player_y;
	int		is_nev;
	int		step;
	char	*step_str;
	int		done;
	int		p;
	int		c;
	int		e;

	char	*maz_img;
	char	*asf_img;
	char	*kon_img;
	char	*gor_img;
	char	*nev_img;

	void	*asf;
	void	*kon;
	void	*maz;
	void	*nev;
	void	*gor;

	void	*mlx;
	void	*window;

}t_data;

void	ft_game(t_data data);
int		ft_map_processing(char *map, t_data *data);
int		ft_see_map(t_data *data);
int		ft_see_wall(t_data data);
int		ft_see_symbol(t_data data);
void	ft_win(t_data *data);

int		ft_key(int keycode, t_data *data);
int		ft_key_exit(t_data *data);
void	ft_key_A(t_data *data, int j, int i);
void	ft_key_D(t_data *data, int j, int i);
void	ft_key_W(t_data *data, int i, int j);
void	ft_key_S(t_data *data, int i, int j);

int		ft_is_1_W(t_data *data, int i, int j);
int		ft_is_E(t_data *data, int i, int j);

void	ft_init_image(t_data *data);
void	ft_back(t_data *data);
void	ft_konus(t_data *data);
void	ft_mazda(t_data *data);
void	ft_nevesta(t_data *data);
void	ft_exit(t_data *data);

int		ft_step(t_data *data);
void	ft_go_left(t_data *data, int i, int j);
void	ft_go_right(t_data *data, int i, int j);
void	ft_go_up(t_data *data, int i, int j);
void	ft_go_down(t_data *data, int i, int j);

int		ft_height(char *map);
int		ft_width(char *map);
int		ft_error(t_data *data);

int		ft_strlen(const char *s);
int		ft_is_char(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
char	*ft_itoa(int n);
int		ft_kolvo(int n);
void	ft_clear(char **str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_out_gnl(int i, char **buf, char **remain);
void	ft_gnl_in_str(char **buf, char **str, char **gnl);
void	ft_gnl_in_line(char **line, char **str, char **gnl);
int		ft_gnl(int fd, char **line);
char	*ft_g_n_l(int fd, char **line);

void	ft_clear_mas(t_data data);
void	ft_clear_mas_val(t_data *data);

#endif
