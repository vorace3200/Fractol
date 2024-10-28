/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:23:23 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 16:40:44 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	init_fractol(t_fractol *params, char **b)
{
	params->zoom = 1.0;
	params->max_iterations = 200;
	params->color_shift = 1;
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
		params->julia_real = -0.7;
		params->julia_imaginary = 0.27015;
	}
	else if (ft_strcmp(b[1], "burning_ship") == 0)
		params->fractal_type = BURNING_SHIP;
	else
	{
		write(1, "Erreur: Type de fractale inconnu\n", 33);
		return (0);
	}
	return (1);
}
