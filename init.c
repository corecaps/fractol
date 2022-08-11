/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:39:08 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/11 15:05:07 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/******************************************************************************
 * initialise the window and image buffer                                     *
 *****************************************************************************/

void	init_win(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->size_x + 2,
			data->size_y + 2,
			"fractol");
	data->img_buffer->img = mlx_new_image(data->mlx,
			data->size_x + 1,
			data->size_y + 1);
	data->img_buffer->address = mlx_get_data_addr(data->img_buffer->img,
			&data->img_buffer->bit_per_pixel,
			&data->img_buffer->line_length,
			&data->img_buffer->endian);
}

/******************************************************************************
 * print help information if cli args are incorrect                           *
 *****************************************************************************/

void	print_usage(char **argv, t_data *data)
{
	ft_printf("INVALID ARGUMENT\n");
	ft_printf("Usage:\n\t %s [options] fractal_type\n", argv[0]);
	ft_printf("fractal_type :\n\tmandelbrot\n\tjulia\n\tburningship\n");
	ft_printf("Options :\n\t-s size\toverride the default windows size to size\n");
	ft_printf("Options :\n\t-a animation mask\t\n\t\t1:\t color shift\n");
	ft_printf("\t\t2:\tJulia cyclic animation\n");
	ft_printf("\t\t3:\tContinuous Zoom in\n");
	free(data->img_buffer);
	free(data);
	exit(1);
}

/******************************************************************************
 * allocate space on the heap for the data structure                          *
 * @return NULL in case of allocation error otherwise a pointer to the data   *
 * structure                                                                  *
 *****************************************************************************/

t_data	*alloc_mem(void)
{
	t_data	*data;

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

/******************************************************************************
 * initialize the data structure with defaults values                         *
 * most of them are defined in config.h                                       *
 *****************************************************************************/

void	init_data(t_data *data)
{
	data->size_x = DEFAULT_X;
	data->size_y = DEFAULT_Y;
	data->center_x = DEFAULT_CENTER_X;
	data->center_y = DEFAULT_CENTER_Y;
	data->zoom_factor_x = DEFAULT_ZOOM_FACTOR;
	data->zoom_factor_y = DEFAULT_ZOOM_FACTOR;
	update_coord(data);
	data->redraw = 1;
	data->algorithm = NULL;
	data->max_iter = MAX_ITER;
	data->color_offset = 0;
	data->exit = 0;
	data->anim = 0;
	get_args(data);
	data->mlx = mlx_init();
	init_win(data);
}

/******************************************************************************
 * initialize the data structure, mlx library, application windows            *
 * @return NULL in case of allocation error, otherwise a pointer to data      *
 * structure                                                                  *
 *****************************************************************************/

t_data	*main_init(int argc, char **argv)
{
	t_data	*data;

	data = alloc_mem();
	if (data == NULL)
		return (NULL);
	data->argc = argc;
	data->argv = argv;
	init_data(data);
	return (data);
}
