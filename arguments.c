/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:11:05 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/11 17:11:52 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_opt_value(const t_data *data, int *argp, int *buf)
{
	(*argp)++;
	(*buf) = ft_atoi(data->argv[(*argp)]);
}

/******************************************************************************
 * get value from flags                                                       *
 *****************************************************************************/

int	get_opt(t_data *data, int argp)
{
	int	buf;

	if (data->argv[argp][1] == 's')
	{
		get_opt_value(data, &argp, &buf);
		if (buf > 10 && buf < 2000)
		{
			data->size_x = buf + 1;
			data->size_y = buf + 1;
		}
		else
			print_usage(data->argv, data);
	}
	else if (data->argv[argp][1] == 'a')
	{
		get_opt_value(data, &argp, &buf);
		if (buf > 0 && buf < 10)
			data->anim = buf;
		else
			print_usage(data->argv, data);
	}
	return (argp);
}

/******************************************************************************
 * Set the rendering algorithm
 *****************************************************************************/

int	set_algorithm(int argp, char *arg, t_data *data)
{
	if (ft_strcmp(arg, "mandelbrot") == 0 && argp + 1 == data->argc)
	{
		data->algorithm = mandelbrot_escape;
		return (0);
	}
	else if (ft_strcmp(arg, "julia") == 0 && argp + 1 == data->argc)
	{
		data->algorithm = julia_escape;
		data->max_iter = 90;
		return (0);
	}
	else if (ft_strcmp(arg, "burningship") == 0 && argp + 1 == data->argc)
	{
		data->algorithm = burning_escape;
		data->max_iter = 100;
		return (0);
	}
	else
		return (1);
}

/******************************************************************************
 * check cli arguments and save the simulation parameters in data structure   *
 *****************************************************************************/

void	get_args(t_data *data)
{
	int		argp;

	if (data->argc > 1)
	{
		argp = 1;
		while (argp < data->argc)
		{
			if (data->argv[argp][0] == '-' && data->argc > argp + 1)
			{
				argp = get_opt(data, argp);
			}
			else if (set_algorithm(argp, data->argv[argp], data) == 0)
				break ;
			else
				print_usage(data->argv, data);
			argp ++;
		}
	}
	if (data->algorithm == NULL)
		print_usage(data->argv, data);
}
