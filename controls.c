/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:02:34 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/11 15:01:36 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/******************************************************************************
 * function is called via mlx hook
 * keys affect the configuration of the simulation
 * keycode value are defined in config.h
 * @return 0 in every cases
 *****************************************************************************/

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->center_y -= data->zoom_factor_y * 4;
	else if (keycode == KEY_DOWN)
		data->center_y += data->zoom_factor_y * 4;
	else if (keycode == KEY_LEFT)
		data->center_x -= data->zoom_factor_x * 4;
	else if (keycode == KEY_RIGHT)
		data->center_x += data->zoom_factor_x * 4;
	else if (keycode == KEY_1)
		data->anim ^= 1;
	else if (keycode == KEY_2)
		data->anim ^= 2;
	else if (keycode == KEY_3)
		data->anim ^= 4;
	else if (keycode == KEY_SPACE)
		data->anim = 0;
	else if (keycode == KEY_ESC)
		win_close(data);
	update_coord(data);
	return (0);
}

/******************************************************************************
 * update data structure to zoom in or out                                    *
 *****************************************************************************/
void	zoom(t_data *data, t_complex new_center, long double zoom_factor,
				int iter_mod)
{
	data->center_x = (data->center_x + new_center.r) / 2;
	data->center_y = (data->center_y + new_center.i) / 2;
	data->zoom_factor_x *= zoom_factor;
	data->zoom_factor_y *= zoom_factor;
	if (data->max_iter < MAX_ITER * MAX_MAX_ITER)
	{
		data->max_iter += iter_mod;
	}
	update_coord(data);
}
/******************************************************************************
 * function called via mlx hook to handle mouse event                         *
 * scrolling zoom into simulation                                             *
 * left click set a new point for julia simulation                            *
 *****************************************************************************/

int	mouse_events(int button, int x, int y, t_data *data)
{
	t_complex	new_center;

	new_center = warp_coord_to_complex(x, y, data);
	if (button == 4)
		zoom(data, new_center, (1 - (ZOOM / 100)), 2);
	else if (button == 5)
		zoom(data, new_center, (1 + (ZOOM / 100)), -2);
	else if (button == 1)
	{
		data->julia_c = new_center;
		data->redraw = 1;
	}
	return (0);
}

/******************************************************************************
 * update the pixel and complex coordinate system                             *
 *****************************************************************************/

void	update_coord(t_data *data)
{
	data->cplx_size_x = data->size_x * data->zoom_factor_x;
	data->cplx_size_y = data->size_y * data->zoom_factor_y;
	data->start_r = data->center_x - (data->cplx_size_x / 2);
	data->stop_r = data->center_x + (data->cplx_size_x / 2);
	data->start_i = data->center_y - (data->cplx_size_x / 2);
	data->stop_i = data->center_y + (data->cplx_size_y / 2);
	data->redraw = 1;
}
