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
# include <unistd.h>
# include "config.h"

typedef struct s_complex
{
	double real;
	double imaginary;
} t_complex;

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
	int 		size_x;
	int 		size_y;
}t_data;

int		render(t_data *data);
void	get_args(int argc, char **argv, t_data *data);
t_data	*main_init(void);
#endif //FRACTOL_FRACTOL_H