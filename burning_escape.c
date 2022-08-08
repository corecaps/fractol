//
// Created by corecaps on 08/08/22.
//
#include "fractol.h"
static int calc_escape(t_data *data,t_complex p)
{
	int iter;
	long double tmp;
	t_complex c;

	iter = 0;
	c = p;
	while (((p.r * p.r) + (p.i * p.i) < 4.0L) && (iter < data->max_iter))
	{
		tmp = ((p.r * p.r) - (p.i * p.i)) + c.r;
		p.i = fabsl(2.0L * p.r * p.i) + c.i;
		p.r = tmp;
		iter ++;
	}
	return iter;
}
void burning_escape(t_data *data)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y ++ < data->size_y - 1)
	{
		x = 0;
		while (x ++ < data->size_x - 1)
		{
			color = calc_escape(data, warp_coord_to_complex(x,y,data));
			put_pixel_2_img(data->img_buffer,x,y, get_color(data,color));
		}
	}
}