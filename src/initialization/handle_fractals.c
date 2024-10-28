/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:36:50 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 17:46:41 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handle_fractals(t_fractol *params)
{
	if (params->fractal_type == MANDELBROT)
		mandelbrot(params);
	else if (params->fractal_type == JULIA)
		julia(params);
}