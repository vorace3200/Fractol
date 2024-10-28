/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:58:29 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 17:57:12 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color_scheme0(int iteration, t_fractol *params)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iteration / params->max_iterations;
	r = 9 * (1 - t) * t * t * t * 255;
	g = 15 * (1 - t) * (1 - t) * t * t * 255;
	b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return ((r << 16) | (g << 8) | b);
}

int	get_color_scheme1(int iteration, t_fractol *params)
{
	int	r;
	int	g;
	int	b;

	r = sin(0.16 * iteration + 4) * 127 + 128;
	g = sin(0.16 * iteration + 2) * 127 + 128;
	b = sin(0.16 * iteration) * 127 + 128;
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int iteration, t_fractol *params)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == params->max_iterations)
		return (0x000000);
	if (params->color_scheme == 0)
		return (get_color_scheme0(iteration, params));
	else if (params->color_scheme == 1)
		return (get_color_scheme1(iteration, params));
	else if (params->color_scheme == 2)
		return ((iteration * 255 / params->max_iterations) * 0x010101);
	else
	{
		t = (double)iteration / params->max_iterations;
		r = t * 128;
		g = 0;
		b = t * 255;
		return ((r << 16) | (g << 8) | b);
	}
}

int	close_window(t_fractol *params)
{
	mlx_destroy_window(params->mlx, params->win);
	exit(0);
	return (0);
}
