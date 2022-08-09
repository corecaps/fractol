/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_escape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:44:13 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 00:34:11 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	calc_escape(t_data *data, t_complex c, t_complex p)
{
	long double	tmp;
	int			iter;

	iter = 0;
	while ((p.r * p.r + p.i * p.i <= 4) && (iter < data->max_iter))
	{
		tmp = p.r * p.r - p.i * p.i + c.r;
		p.i = 2 * p.r * p.i + c.i;
		p.r = tmp;
		iter ++;
	}
	return (iter);
}

void	julia_escape(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y ++ < data->size_y - 1)
	{
		x = 0;
		while (x ++ < data->size_x - 1)
		{
			color = calc_escape(data, data->julia_c,
					warp_coord_to_complex(x, y, data));
			put_pixel_2_img(data->img_buffer, x, y, get_color(data, color));
		}
	}
}