/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:08:02 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/22 18:08:07 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
#define FRACTOL_FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
typedef struct s_buffer
{
	void	*img;
	char 	*address;
	int 	bit_per_pixel;
	int 	line_length;
	int 	endian;
} t_buffer;
typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_buffer	*img_buffer;
}t_data;


#endif //FRACTOL_FRACTOL_H