/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:15:18 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/01 18:49:04 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_pressed(int keycode, t_data *data)
{
    if (keycode == KEY_UP)
        data->center_y -= data->zoom_factor_y * 4;
    else if (keycode == KEY_DOWN)
        data->center_y += data->zoom_factor_y * 4;
    else if (keycode == KEY_LEFT)
        data->center_x -= data->zoom_factor_x * 4;
    else if (keycode == KEY_RIGHT)
        data->center_x += data->zoom_factor_x * 4;
    else if (keycode == KEY_ESC)
    {
        mlx_destroy_window(data->mlx,data->mlx_win);
    }
	update_coord(data);
	// TODO SPACE Start Stop animation
	// TODO Key to inc max_iter
	// TODO Key to dec max_iter
	// TODO Keys to activate deactivate animation function
    return (0);
}

int mouse_events(int button, int x, int y, t_data *data)
{
	t_complex	new_center;

	new_center = warp_coord_to_complex(x,y,data);
	data->center_x = (data->center_x + new_center.r) / 2;
	data->center_y = (data->center_y + new_center.i) / 2;
    if (button == 4)
    {
		data->zoom_factor_x *= 0.90;
		data->zoom_factor_y *= 0.90;
		if (data->max_iter < MAX_ITER *  500)
			data->max_iter += 2;
		update_coord(data);
	}
    else if (button == 5)
    {
		data->zoom_factor_x *= 1.1;
		data->zoom_factor_y *= 1.1;
		if (data->max_iter > MAX_ITER)
			data->max_iter -= 2;
		update_coord(data);
	}
	// TODO Click when julia set c cplx number
    return (0);
}

void update_coord(t_data *data)
{
	data->cplx_size_x = data->size_x * data->zoom_factor_x;
	data->cplx_size_y = data->size_y * data->zoom_factor_y;
	data->start_r = data->center_x - (data->cplx_size_x / 2);
	data->stop_r = data->center_x + (data->cplx_size_x / 2);
	data->start_i = data->center_y - (data->cplx_size_x /2);
	data->stop_i = data->center_y + (data->cplx_size_y /2);
	data->redraw = 1;
}