/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:43:51 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/11 15:07:39 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/******************************************************************************
 * Close windows and exit cleanly                                             *
 *****************************************************************************/

int	win_close(t_data *data)
{
	data->exit = 1;
	mlx_destroy_window(data->mlx, data->mlx_win);
	clean_exit(data);
	return (0);
}

/******************************************************************************
 * free every space still allocated on the heap                               *
 * and exit with success                                                      *
 *****************************************************************************/

void	clean_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_buffer->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->img_buffer);
	free(data);
	exit(0);
}
