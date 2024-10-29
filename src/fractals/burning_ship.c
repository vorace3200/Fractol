/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:12:01 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 21:37:10 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	compute_burning_ship(double cx, double cy, t_fractol *params)
{
	int		iteration;
	double	zx;
	double	zy;
	double	temp;

	zx = 0;
	zy = 0;
	iteration = 0;
	while (zx * zx + zy * zy <= 4 && iteration < params->max_iterations)
	{
		temp = zx * zx - zy * zy + cx;
		zy = fabs(2 * zx * zy) + cy;
		zx = temp;
		iteration++;
	}
	return (iteration);
}

void	burning_ship(t_fractol *params)
{
	int		x;
	int		y;
	double	cx;
	double	cy;
	int		iteration;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			cx = (x - 250.0) / (125.0 * params->zoom) + params->offset_x - 0.5;
			cy = (y - 250.0) / (125.0 * params->zoom) + params->offset_y;
			iteration = compute_burning_ship(cx, cy, params);
			my_mlx_pixel_put(params, x, y, get_color(iteration, params));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
}
