/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:02:33 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 16:40:54 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	entry_main(char **b)
{
	t_fractol	params;

	params.mlx = mlx_init();
	if (!params.mlx)
	{
		write(1, "Error initializing MLX\n", 23);
		return (0);
	}
	if (!init_fractol(&params, b))
	{
		write(1, "Error initializing parameters\n", 30);
		return (0);
	}
	params.win = mlx_new_window(params.mlx, 500, 500, "Fractol");
	if (!params.win)
	{
		write(1, "Error creating window\n", 22);
		return (0);
	}
	handle_fractals(&params);
	mlx_key_hook(params.win, handle_keys, &params);
	mlx_mouse_hook(params.win, handle_mouse, &params);
	mlx_hook(params.win, 17, 0L, close_window, &params);
	mlx_loop(params.mlx);
	return (1);
}
