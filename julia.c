/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:26:16 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/10 17:14:00 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_julia(double real, double imag, double re, double im)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	tmp;

	z_real = real;
	z_imag = imag;
	i = 0;
	while (i < 100)
	{
		tmp = (z_real * z_real) - (z_imag * z_imag) + re;
		z_imag = 2 * z_real * z_imag + im;
		z_real = tmp;
		if ((z_real * z_real) + (z_imag * z_imag) > 4)
			return (100 - i);
		i++;
	}
	return (0);
}

static	int	color_(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == 100)
		return (0x000000);
	t = (double)iteration / max_iter;
	r = (int)(9 * (1 - t) * (t * t * t) * 255);
	g = (int)(15 * (1 - t) * (1 - t) * (t * t) * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

void	draw_julia(t_mlx *mlx, double r, double i)
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
			real = get_coordinates(x, -2.0, 2.0, WIDTH) * mlx->zoom;
			imag = get_coordinates(y, 2.0, -2.0, HEIGHT) * mlx->zoom;
			color = color_(iterate_julia(real, imag, r, i), 100);
			put_pixel(mlx, x, y, color);
			x++;
		}
		y++;
	}
}
