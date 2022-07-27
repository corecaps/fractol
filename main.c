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

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = main_init();
	if (data == NULL)
	{
		write(1,"allocation error\n",17);
		return (1);
	}
	get_args(argc,argv, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
	return (0);
}
