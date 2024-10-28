/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:22:03 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 16:40:31 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_mouse(int button, int x, int y, t_fractol *params)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (x - 500.0 / 2) / (125.0 * params->zoom) + params->offset_x;
	mouse_y = (y - 500.0 / 2) / (125.0 * params->zoom) + params->offset_y;
	if (button == 4)
	{
		params->zoom *= 1.2;
		params->offset_x = mouse_x - (x - 500.0 / 2) / (125.0 * params->zoom);
		params->offset_y = mouse_y - (y - 500.0 / 2) / (125.0 * params->zoom);
	}
	else if (button == 5)
	{
		params->zoom /= 1.2;
		params->offset_x = mouse_x - (x - 500.0 / 2) / (125.0 * params->zoom);
		params->offset_y = mouse_y - (y - 500.0 / 2) / (125.0 * params->zoom);
	}
	handle_fractals(params);
	return (0);
}
