/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:08:02 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/11 15:02:18 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "config.h"
# include "libftprintf/ft_printf.h"

typedef struct s_complex
{
	long double	r;
	long double	i;
}	t_complex;
typedef struct s_buffer
{
	void	*img;
	char	*address;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_buffer;
typedef struct s_data
{
	int			argc;
	char		**argv;
	void		*mlx;
	void		*mlx_win;
	t_buffer	*img_buffer;
	int			size_x;
	int			size_y;
	long double	start_r;
	long double	stop_r;
	long double	start_i;
	long double	stop_i;
	long double	cplx_size_x;
	long double	cplx_size_y;
	long double	center_x;
	long double	center_y;
	long double	zoom_factor_x;
	long double	zoom_factor_y;
	t_complex	julia_c;
	int			color_offset;
	int			redraw;
	int			max_iter;
	int			anim;
	int			exit;
	void		(*algorithm)(struct s_data *);
}t_data;
int			render(t_data *data);
void		get_args(t_data *data);
t_data		*main_init(int argc, char **argv);
t_complex	warp_coord_to_complex(int x, int y, t_data *data);
void		put_pixel_2_img(t_buffer *img, int x, int y, int color);
void		mandelbrot_escape(t_data *data);
int			key_pressed(int keycode, t_data *data);
int			mouse_events(int button, int x, int y, t_data *data);
int			get_mlx_color(double red, double green, double blue);
int			hsv_to_rgb(int hue, int sat, int value, int offset);
void		update_coord(t_data *data);
void		julia_escape(t_data *data);
int			get_color(const t_data *data, int iter);
char		*ft_itoa(int n);
int			ft_atoi(const char *nptr);
t_complex	julia_anim(t_data *data, t_complex *c);
void		animations(t_data *data);
void		burning_escape(t_data *data);
void		clean_exit(t_data *data);
int			win_close(t_data *data);
int			ft_strcmp(const char *s1, const char *s2);
void		print_usage(char **argv, t_data *data);
#endif
