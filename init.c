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
#include <string.h>

void	get_args(t_data *data)
{
    int argp;
    int argc = data->argc;
    char **argv = data->argv;

    if (argc > 1)
    {
        argp = 1;
        while (argp < argc)
        {
            if (argv[argp][0] == '-')
            {
                if (argv[argp][1] == 's')
                {
                    argp++;
                    data->size_x = atoi(argv[argp]) + 1;
                    data->size_y = atoi(argv[argp]) + 1; // TODO : utiliser ft_atoi
                }
            }
            if (strcmp(argv[argp], "mandelbrot") == 0) // TODO : utiliser ft_printf
            {
                data->algorithm = mandelbrot_escape;
                break;
            }
			else if (strcmp(argv[argp], "julia") == 0) // TODO : utiliser ft_printf
			{
				data->algorithm = julia_escape;
				break;
			}
            argp ++;
        }
    }
    if (data->algorithm == NULL)
    {
        printf("Usage:\n\t %s [options] fractal_type\n",argv[0]);
        printf("fractal_type :\n\tmandelbrot\n\tjulia\n");
        printf("Options :\n\t-s size\toverride the default windows size to size\n");
        exit(1);
    }
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
	// TODO use update coord to limit func size
	data->start_i = -1.13;
	data->stop_i = 1.13;
	data->start_r = -1.7;
	data->stop_r = 0.5;
	data->center_x = (data->start_r + data->stop_r) / 2;
	data->center_y = (data->start_i + data->stop_i) / 2;
	data->cplx_size_x = (data->stop_r - data->start_r);
	data->cplx_size_y = data->stop_i - data->start_i;
	data->zoom_factor_x  = data->cplx_size_x / data->size_x;
	data->zoom_factor_y = data->cplx_size_y /data->size_y;
	data->redraw = 1;
    data->algorithm = NULL;
	data->max_iter = MAX_ITER;
    get_args(data);
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

t_data *main_init(int argc, char **argv)
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