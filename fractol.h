/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:08:02 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/22 18:08:07 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
#define FRACTOL_FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "config.h"

typedef struct s_complex
{
	double r;
	double i;
} t_complex;

typedef struct s_buffer
{
	void	*img;
	char 	*address;
	int 	bit_per_pixel;
	int 	line_length;
	int 	endian;
} t_buffer;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_buffer	*img_buffer;
	int 		size_x;
	int 		size_y;
	double		start_r;
	double 		stop_r;
	double 		start_i;
	double 		stop_i;
}t_data;

int		render(t_data *data);
void	get_args(int argc, char **argv, t_data *data);
t_data	*main_init(void);
t_complex warp_coord_to_complex(int x, int y, t_data *data);
void put_pixel_2_img(t_buffer *img,int x, int y, int color);
void render_escape(t_data *data);
int key_pressed(int keycode, t_data *data);
int mouse_events(int button, int x, int y, t_data *data);
int rgb_to_mlx_color(int red, int green,int blue);
int	hsv_to_rgb(int hue, int sat, int value);
#endif //FRACTOL_FRACTOL_H