/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:39:08 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 00:30:58 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>

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

void	print_usage(char **argv, t_data *data)
{
	printf("Usage:\n\t %s [options] fractal_type\n", argv[0]);
	printf("fractal_type :\n\tmandelbrot\n\tjulia\n");
	printf("Options :\n\t-s size\toverride the default windows size to size\n");
	free(data->img_buffer);
	free(data);
	exit(1);
}

void	get_args(t_data *data)
{
	int		argp;
	int		buf;

	if (data->argc > 1)
	{
		argp = 1;
		while (argp < data->argc)
		{
			if (data->argv[argp][0] == '-' && data->argc > argp + 1)
			{
				if (data->argv[argp][1] == 's')
				{
					argp++;
					buf = atoi(data->argv[argp]);
					if (buf > 0)
					{
						data->size_x = buf + 1;
						data->size_y = buf + 1; // TODO : utiliser ft_atoi
					}
					else
					{
						printf("invalid argument\n");
						print_usage(data->argv, data);
					}
				}
			}
			else if (strcmp(data->argv[argp], "mandelbrot") == 0
					&& argp + 1 == data->argc) // TODO : utiliser ft_printf
			{
				data->algorithm = mandelbrot_escape;
				break ;
			}
			else if (strcmp(data->argv[argp], "julia") == 0
					&& argp + 1 == data->argc) // TODO : utiliser ft_printf
			{
				data->algorithm = julia_escape;
				data->max_iter = 90;
				break ;
			}
			else if (strcmp(data->argv[argp], "burning") == 0
					&& argp + 1 == data->argc) // TODO : utiliser ft_printf
			{
				data->algorithm = burning_escape;
				data->max_iter = 100;
				break ;
			}
			else
			{
				printf("Invalid argument\n");
				print_usage(data->argv, data);
			}
			argp ++;
		}
	}
	if (data->algorithm == NULL)
	{
		print_usage(data->argv, data);
	}
}

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

void	init_data(t_data *data)
{
	data->size_x = DEFAULT_X;
	data->size_y = DEFAULT_Y;
	// TODO use update coord to limit func size
	data->start_i = -1.13;
	data->stop_i = 1.13;
	data->start_r = -1.7;
	data->stop_r = 0.5;
	data->center_x = (data->start_r + data->stop_r) / 2;
	data->center_y = (data->start_i + data->stop_i) / 2;
	data->cplx_size_x = (data->stop_r - data->start_r);
	data->cplx_size_y = data->stop_i - data->start_i;
	data->zoom_factor_x = data->cplx_size_x / data->size_x;
	data->zoom_factor_y = data->cplx_size_y / data->size_y;
	data->redraw = 1;
	data->algorithm = NULL;
	data->max_iter = MAX_ITER;
	data->color_offset = 0;
	data->exit = 0;
	get_args(data);
	data->mlx = mlx_init();
	init_win(data);
}

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
