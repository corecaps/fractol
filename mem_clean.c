/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:43:51 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 00:44:13 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*******************************************************************************
 * free every space still allocated on the heap                                *
 * and exit with success                                                       *
 ******************************************************************************/

void	clean_exit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_buffer->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->img_buffer);
	free(data);
	exit(0);
}