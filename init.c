/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:39:08 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/27 12:39:12 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_args(int argc, char **argv, t_data *data)
{
	(void) argc;
	(void) argv;
	(void) data;
}

t_data *alloc_mem()
{
	t_data *data;

	data = malloc(sizeof (t_data));
	if (data == NULL)
		return (NULL);
	data->img_buffer = malloc(sizeof (t_buffer));
	if (data->img_buffer == NULL)
	{
		free(data);
		return (NULL);
	}
	return (data);

}

void init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->size_x = DEFAULT_X;
	data->size_y = DEFAULT_Y;
	data->start_i = -1.13;
	data->stop_i = 1.13;
	data->start_r = -1.7;
	data->stop_r = 0.56
			;
	data->center_x = (data->start_r + data->stop_r) / 2;
	data->center_y = (data->start_i + data->stop_i) / 2;
	data->cplx_size_x = (data->stop_r - data->start_r);
	data->cplx_size_y = data->stop_i - data->start_i;
	data->zoom_factor_x  = data->cplx_size_x / data->size_x;
	data->zoom_factor_y = data->cplx_size_y /data->size_y;
	data->mlx_win = mlx_new_window(data->mlx, data->size_x+1, data->size_y+1,
								   "fractol");
	data->img_buffer->img = mlx_new_image(data->mlx,
										  data->size_x + 1,
										  data->size_y + 1);
	data->img_buffer->address = mlx_get_data_addr(data->img_buffer->img,
												  &data->img_buffer->bit_per_pixel,
												  &data->img_buffer->line_length,
												  &data->img_buffer->endian);
}

t_data	*main_init(void)
{
	t_data	*data;

	data = alloc_mem();
	if (data == NULL)
		return (NULL);
	init_data(data);
	return (data);
}