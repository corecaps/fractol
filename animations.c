/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:38:54 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 01:39:05 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_animation(t_data *data)
{
	data->zoom_factor_x *= 0.95;
	data->zoom_factor_y *= 0.95;
	data->max_iter += 1;
	update_coord(data);
	data->redraw = 1;
}

void color_shift(t_data *data)
{
	data->redraw = 1;
	if (data->color_offset < 360)
		data->color_offset += 3;
	else
		data->color_offset = 0;
}

/*******************************************************************************
 * update variable in data structure to handle animation parameters            *
 ******************************************************************************/

void	animations(t_data *data)
{
	if ((data->anim & 1) == 1)
		color_shift(data);
	if ((data->anim & 2) == 2)
		data->julia_c = julia_anim(data, &data->julia_c);
	if ((data->anim & 4) == 4)
		zoom_animation(data);
}

/*******************************************************************************
 * move the point for julia set in the complex plane                           *
 ******************************************************************************/

t_complex	julia_anim(t_data *data, t_complex *c)
{
	static double	angle = 0.0;
	static int		sens = 1;

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