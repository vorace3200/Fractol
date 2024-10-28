/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:50:21 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 17:57:53 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	compute_julia(double zx, double zy, t_fractol *params)
{
	int		iteration;
	double	temp;

	iteration = 0;
	while (zx * zx + zy * zy <= 4 && iteration < params->max_iterations)
	{
		temp = zx * zx - zy * zy + params->julia_real;
		zy = 2 * zx * zy + params->julia_imaginary;
		zx = temp;
		iteration++;
	}
	return (iteration);
}

void	julia(t_fractol *params)
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	int		iteration;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			zx = (x - 250.0) / (125.0 * params->zoom) + params->offset_x;
			zy = (y - 250.0) / (125.0 * params->zoom) + params->offset_y;
			iteration = compute_julia(zx, zy, params);
			my_mlx_pixel_put(params, x, y, get_color(iteration, params));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
}
