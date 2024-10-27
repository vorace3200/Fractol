/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:48:30 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/27 13:10:02 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minilibx-linux/mlx.h"

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
    mlx_loop(mlx);
    return (0);
}