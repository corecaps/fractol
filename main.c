/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:58:30 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/22 17:58:33 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	get_args(int argc,char **argv,t_data *data)
{

}

t_data	*main_init(void)
{
	t_data	*data;
	data = malloc(sizeof (t_data));
	if (data == NULL)
		return (NULL);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 640, 480,
								   "fractol");
	data->img_buffer->img = mlx_new_image(data->mlx,
										  640,
										  480);
	data->img_buffer->address = mlx_get_data_addr(data->img_buffer->img,
												  &data->img_buffer->bit_per_pixel,
												  &data->img_buffer->line_length,
												  &data->img_buffer->endian);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;


	data = NULL;
	data = main_init();
	get_args(argc,argv, data);
	mlx_loop(data->mlx);
	return (0);
}