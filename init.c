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

/*******************************************************************************
 * initialise the window and image buffer                                       *
 ******************************************************************************/

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
/*******************************************************************************
 * print help information if cli args are incorrect                            *
 ******************************************************************************/

void	print_usage(char **argv, t_data *data)
{
	// TODO : utiliser ft_printf
	ft_printf("Usage:\n\t %s [options] fractal_type\n", argv[0]);
	ft_printf("fractal_type :\n\tmandelbrot\n\tjulia\n");
	ft_printf("Options :\n\t-s size\toverride the default windows size to size\n");
	free(data->img_buffer);
	free(data);
	exit(1);
}

/*******************************************************************************
 * check cli arguments and save the simulation parameters in data structure    *
 ******************************************************************************/

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
					buf = ft_atoi(data->argv[argp]);
					if (buf > 0)
					{
						data->size_x = buf + 1;
						data->size_y = buf + 1;
					}
					else
					{
						ft_printf("invalid argument\n"); // TODO : utiliser ft_printf
						print_usage(data->argv, data);
					}
				}
			}
			else if (ft_strcmp(data->argv[argp], "mandelbrot") == 0
					&& argp + 1 == data->argc) // TODO ft_strcmp
			{
				data->algorithm = mandelbrot_escape;
				break ;
			}
			else if (ft_strcmp(data->argv[argp], "julia") == 0
					&& argp + 1 == data->argc)
			{
				data->algorithm = julia_escape;
				data->max_iter = 90;
				break ;
			}
			else if (ft_strcmp(data->argv[argp], "burning") == 0
					&& argp + 1 == data->argc)
			{
				data->algorithm = burning_escape;
				data->max_iter = 100;
				break ;
			}
			else
			{
				ft_printf("Invalid argument\n"); // TODO : utiliser ft_printf
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

/*******************************************************************************
 * allocate space on the heap for the data structure                           *
 * @return NULL in case of allocation error otherwise a pointer to the data    *
 * structure                                                                   *
 ******************************************************************************/

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

/*******************************************************************************
 * initialize the data structure with defaults values                          *
 * most of them are defined in config.h                                        *
 ******************************************************************************/

void	init_data(t_data *data)
{
	data->size_x = DEFAULT_X;
	data->size_y = DEFAULT_Y;
	data->center_x = -0.609778L;
	data->center_y = 0.0L;
	data->zoom_factor_x = 0.002444;
	data->zoom_factor_y = 0.002444;
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

/*******************************************************************************
 * initialize the data structure, mlx library, application windows             *
 * @return NULL in case of allocation error, otherwise a pointer to data       *
 * structure                                                                   *
 ******************************************************************************/

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