/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:11:05 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/11 14:11:15 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*******************************************************************************
 * check cli arguments and save the simulation parameters in data structure    *
 ******************************************************************************/

void	get_args(t_data *data)
{
	int		argp;
	int		buf;

	if (data->argc > 1)
	{
		argp = 1;
		while (argp < data->argc)
		{
			if (data->argv[argp][0] == '-' && data->argc > argp + 1)
			{
				if (data->argv[argp][1] == 's')
				{
					argp++;
					buf = ft_atoi(data->argv[argp]);
					if (buf > 0)
					{
						data->size_x = buf + 1;
						data->size_y = buf + 1;
					}
					else
					{
						ft_printf("invalid argument\n");
						print_usage(data->argv, data);
					}
				}
			}
			else if (ft_strcmp(data->argv[argp], "mandelbrot") == 0
					 && argp + 1 == data->argc)
			{
				data->algorithm = mandelbrot_escape;
				break ;
			}
			else if (ft_strcmp(data->argv[argp], "julia") == 0
					 && argp + 1 == data->argc)
			{
				data->algorithm = julia_escape;
				data->max_iter = 90;
				break ;
			}
			else if (ft_strcmp(data->argv[argp], "burning") == 0
					 && argp + 1 == data->argc)
			{
				data->algorithm = burning_escape;
				data->max_iter = 100;
				break ;
			}
			else
			{
				ft_printf("Invalid argument\n");
				print_usage(data->argv, data);
			}
			argp ++;
		}
	}
	if (data->algorithm == NULL)
	{
		print_usage(data->argv, data);
	}
}
