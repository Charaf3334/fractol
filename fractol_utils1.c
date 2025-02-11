/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:29:24 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/11 13:02:46 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = mlx->addr + (y * mlx->line_length + x
				* (mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

double	get_coordinates(int pixel, double max, double min, int size)
{
	return (min + (((max - min) * pixel) / size));
}

void	error_message(int n)
{
	if (!n)
		write (2, "You have multiple choices:\n", 28);
	write (2, "./fractol mandelbrot\n", 22);
	write (2, "or\n", 4);
	write (2, "./fractol julia real imag\n", 27);
	exit(1);
}
