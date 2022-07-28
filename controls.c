//
// Created by jgarcia on 7/28/22.
//

#include "fractol.h"

int key_pressed(int keycode, t_data *data)
{
    if (keycode == KEY_UP)
    {
        data->start_i += 0.01;
        data->stop_i  += 0.01;
    }
    else if (keycode == KEY_DOWN)
    {
        data->start_i -= 0.01;
        data->stop_i -= 0.01;
    }
    else if (keycode == KEY_LEFT)
    {
        data->start_r += 0.01;
        data->stop_r += 0.01;
    }
    else if (keycode == KEY_RIGHT)
    {
        data->start_r -= 0.01;
        data->stop_r -= 0.01;
    }
    else if (keycode == KEY_ESC)
    {
        mlx_destroy_window(data->mlx,data->mlx_win);
    }
    return (0);
}

int mouse_events(int button, int x, int y, t_data *data)
{
    (void) x;
    (void) y;
    if (button == 4)
    {
        data->start_r += 0.01;
        data->stop_r -= 0.01;
        data->start_i += 0.01;
        data->stop_i -= 0.01;
    }
    else if (button == 5)
    {
        data->start_r -= 0.01;
        data->stop_r += 0.01;
        data->start_i -= 0.01;
        data->stop_i += 0.01;
    }
    return (0);
}