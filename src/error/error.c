/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:17:49 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 16:47:12 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_error(int a, char **b)
{
	if (a == 1)
	{
		write(1, "Error\n", 6);
		write(1, "Usage: ./fractol [mandelbrot, julia, burning_ship]\n", 51);
		return (0);
	}
	if (ft_strcmp(b[1], "mandelbrot") == 0 || ft_strcmp(b[1], "julia") == 0
		|| ft_strcmp(b[1], "burning_ship") == 0)
	{
		return (1);
	}
	else
	{
		write(1, "Error\n", 6);
		write(1, "Usage: ./fractol [mandelbrot, julia, burning_ship]\n", 51);
		return (0);
	}
	return (1);
}
