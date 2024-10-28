/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:18:15 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 16:40:37 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define UP_ARROW 65362
#define DOWN_ARROW 65364
#define SPACE 32
#define ESC 65307

int	handle_keys(int key, t_fractol *params)
{
	if (key == 53)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	else if (key == 49)
		params->color_scheme = (params->color_scheme + 1) % 5;
	else if (key == 123)
		params->offset_x -= 0.1 / params->zoom;
	else if (key == 124)
		params->offset_x += 0.1 / params->zoom;
	else if (key == 126)
		params->offset_y -= 0.1 / params->zoom;
	else if (key == 125)
		params->offset_y += 0.1 / params->zoom;
	handle_fractals(params);
	return (0);
}
