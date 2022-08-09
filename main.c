/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:58:30 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 00:35:13 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = main_init(argc, argv);
	if (data == NULL)
	{
		write(1, "allocation error\n", 17);
		return (1);
	}
	mlx_mouse_hook(data->mlx_win, mouse_events, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_pressed, data);
	mlx_loop_hook(data->mlx, render, data);
	// TODO implement close window hook
	mlx_loop(data->mlx);
	clean_exit(data);
	return (0);
}
