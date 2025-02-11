/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:48:39 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/11 13:05:26 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_mandelbrot(double real, double imag, int iterations)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	tmp;

	z_real = real;
	z_imag = imag;
	i = 0;
	while (i < iterations)
	{
		tmp = (z_real * z_real) - (z_imag * z_imag) + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = tmp;
		if ((z_real * z_real) + (z_imag * z_imag) > 4)
			break ;
		i++;
	}
	return (i);
}

static int	color_(int iteration, int max_iter)
{
	int	r;
	int	g;
	int	b;

	if (iteration == max_iter)
		return (0x000000);
	r = (iteration * 8) % 256;
	g = (iteration * 2) % 256;
	b = (iteration * 4) % 256;
	return (r << 16 | g << 8 | b);
}

void	draw_mandelbrot(t_mlx *mlx)
{
	int		x;
	int		y;
	int		color;
	double	real;
	double	imag;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = get_coordinates(x, 1.0, -2.0, WIDTH) * mlx->zoom;
			imag = get_coordinates(y, 1.5, -1.5, HEIGHT) * mlx->zoom;
			color = color_(iterate_mandelbrot(real, imag, 100), 100);
			put_pixel(mlx, x, y, color);
			x++;
		}
		y++;
	}
}
