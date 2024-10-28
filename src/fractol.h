/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorace32 <vorace32000@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:48:55 by vorace32          #+#    #+#             */
/*   Updated: 2024/10/28 16:25:23 by vorace32         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../include/minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

// ===================[ STRUCT ]=================== //
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		color;
	int		iteration;
	int		fractal_type;
	double	zoom;
	double	julia_real;
	double	julia_imaginary;
	int		color_shift;
	int		max_iterations;
	double	offset_x;
	double	offset_y;
	int		color_scheme;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_fractol;

// ===================[ HANDLING ]=================== //
int			handle_error(int a, char **b);
void		handle_fractals(t_fractol *params);
int			handle_keys(int key, t_fractol *params);
int			handle_mouse(int button, int x, int y, t_fractol *params);
// ===================[ ENTRY ]=================== //
int			entry_main(char **b);

// ===================[ UTILS ]=================== //
int			ft_strcmp(const char *s1, const char *s2);
void		my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int			get_color(int iteration, t_fractol *params);
int			close_window(t_fractol *params);
// ===================[ FRACTALS ]=================== //
void		mandelbrot(t_fractol *params);

// ===================[ INIT ]=================== //
int			init_fractol(t_fractol *params, char **b);

#endif
