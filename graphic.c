/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:39:43 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 00:14:08 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*******************************************************************************
 * use mlx_string_put to display user_interface information                    *
 ******************************************************************************/

void	user_interface(t_data *data)
{
	char	*buf;

	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xffffff,
				   "jgarcia's FRACTOL");
	mlx_string_put(data->mlx, data->mlx_win, 10, 25, 0xffffff,
				   "press ESC to exit");
	buf = ft_itoa(data->max_iter);
	mlx_string_put(data->mlx, data->mlx_win, 10, 40, 0xffffff, "iter :");
	mlx_string_put(data->mlx, data->mlx_win, 50, 40, 0xffffff, buf);
	free(buf);
	buf = ft_itoa((int)round((data->size_x / data->cplx_size_x) / 100));// TODO putstring with current param
	mlx_string_put(data->mlx, data->mlx_win, 70, 40, 0xffffff, "zoom :");
	mlx_string_put(data->mlx, data->mlx_win, 120, 40, 0xffffff, buf);
	free(buf);
}

/*******************************************************************************
 * write the value of a pixel in a mlx image                                   *
 * @param img data structure containing the image and its parameter            *
 * @param x coordinate                                                         *
 * @param y coordinate                                                         *
 * @param color value of the pixel in one integer                              *
 ******************************************************************************/

void	put_pixel_2_img(t_buffer *img, int x, int y, int color)
{
	char	*dest;

	dest = img->address + (y * img->line_length + x * (img->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
}

/*******************************************************************************
 * reset all pixel of the mlx image to 0 (black)                               *
 ******************************************************************************/

void	clear_buffer(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			put_pixel_2_img(data->img_buffer, x, y, 0);
			x ++;
		}
		y ++;
	}
}


/*******************************************************************************
 * function called by mlx hook to render every frame                           *
 * frame is rendered only if needed (data->redraw > 0)                         *
 * and application not currently exiting (data->exit == 0)                     *
 ******************************************************************************/

int	render(t_data *data)
{
	if (data->redraw == 1 && data->exit == 0)
	{
		data->redraw = 1;
		clear_buffer(data);
		// TODO array of animation function
		animations(data);
		if (data->algorithm != NULL)
			(*data->algorithm)(data);
		mlx_put_image_to_window(data->mlx,
			data->mlx_win,
			data->img_buffer->img,
			0, 0);
		user_interface(data);
		// TODO implement ITOA
	}
	return (0);
}