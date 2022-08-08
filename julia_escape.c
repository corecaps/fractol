/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:44:13 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/27 12:44:17 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex julia_anim(t_data *data, t_complex *c)
{
	static double angle = 0.0;
	static int sens = 1;
	if (angle > (2 * M_PI))
		sens = -1;
	else if (angle < 0)
		sens = 1;
	angle += sens * (M_PI / 157);
	(*c).r = cos(angle);
	(*c).i = sin(M_E * angle);
	data->redraw = 1;
	return (*c);
}

static int calc_escape(t_data *data, t_complex c, t_complex p)
{
	long double	tmp;
	int	iter = 0;

	while ((p.r * p.r + p.i * p.i <= 4) && (iter < data->max_iter))
	{
		tmp = p.r * p.r - p.i * p.i + c.r;
		p.i = 2 * p.r * p.i + c.i;
		p.r = tmp;
		iter ++;
	}
	return iter;
}

void julia_escape(t_data *data)
{
	int 				x;
	int 				y;
	int 				color;

	 //TODO  move static and call to anim function in render hook
	y = 0;
	while (y ++ < data->size_y -1)
	{
		x = 0;
		while (x ++ < data->size_x -1 )
		{
			color = calc_escape(data, data->julia_c, warp_coord_to_complex(x, y, data));
			put_pixel_2_img(data->img_buffer,x,y,get_color(data, color));
		}
	}
}