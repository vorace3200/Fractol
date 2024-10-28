/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:58:29 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 16:43:33 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iteration, t_fractol *params)
{
	if (iteration == params->max_iterations)
		return (0x000000);
	if (params->color_scheme == 0)
		return (((iteration * 7) << 16) | (0 << 8) | (iteration * 9));
	else if (params->color_scheme == 1)
		return ((iteration * 7) | ((iteration * 8) << 8) | ((iteration
					* 9) << 16));
	else if (params->color_scheme == 2)
		return ((iteration * 255 / params->max_iterations) * 0x010101);
	else if (params->color_scheme == 3)
		return ((0 << 16) | ((iteration * 8) << 8) | (iteration * 9));
	else
		return (0xFFFFFF);
}

int	close_window(t_fractol *params)
{
	mlx_destroy_window(params->mlx, params->win);
	exit(0);
	return (0);
}
