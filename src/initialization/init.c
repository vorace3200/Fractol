/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:23:23 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/29 12:26:40 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_julia_params(t_fractol *params, char **b)
{
	params->fractal_type = JULIA;
	params->julia_real = -0.35;
	params->julia_imaginary = 0.6;
	if (b[2] && b[3])
	{
		if (!ft_strisdigit(b[2]) || !ft_strisdigit(b[3]))
		{
			write(1, "Error: Invalid Julia parameters\n", 31);
			return (0);
		}
		params->julia_real = ft_atoi(b[2]) / 1000.0;
		params->julia_imaginary = ft_atoi(b[3]) / 1000.0;
	}
	return (1);
}

int	init_fractol(t_fractol *params, char **b)
{
	params->zoom = 1.0;
	params->max_iterations = 4500;
	params->offset_x = 0.0;
	params->offset_y = 0.0;
	params->color_scheme = 0;
	params->img = mlx_new_image(params->mlx, 500, 500);
	params->addr = mlx_get_data_addr(params->img, &params->bits_per_pixel,
			&params->line_length, &params->endian);
	if (ft_strcmp(b[1], "mandelbrot") == 0)
		params->fractal_type = MANDELBROT;
	else if (ft_strcmp(b[1], "julia") == 0)
	{
		if (!handle_julia_params(params, b))
			return (0);
	}
	else if (ft_strcmp(b[1], "burning_ship") == 0)
	{
		params->fractal_type = BURNING_SHIP;
	}
	else
	{
		write(1, "Error: Unknown fractal type\n", 28);
		return (0);
	}
	return (1);
}
