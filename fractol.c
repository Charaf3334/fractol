/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:23:49 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/11 14:17:07 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rendering(t_mlx *mlx, int choice)
{
	if (choice == 1)
		draw_mandelbrot(mlx);
	else if (choice == 2)
		draw_julia(mlx, mlx->r, mlx->i);
	else
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(1);
	}
}

int	window(t_mlx mlx)
{
	mlx.mlx = mlx_init();
	mlx.zoom = 1;
	if (!mlx.mlx)
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, mlx.title);
	if (!mlx.win)
		return (mlx_destroy_display(mlx.mlx), free(mlx.mlx), 1);
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	if (!mlx.img)
		return (mlx_destroy_window(mlx.mlx, mlx.win),
			mlx_destroy_display(mlx.mlx), free(mlx.mlx), 1);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
			&mlx.endian);
	if (!mlx.addr)
		return (mlx_destroy_image(mlx.mlx, mlx.img),
			mlx_destroy_window(mlx.mlx, mlx.win), mlx_destroy_display(mlx.mlx),
			free(mlx.mlx), 1);
	rendering(&mlx, mlx.choice);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	close_handle(&mlx);
	hooks_handle(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.choice = check_args(ac, av);
	mlx.title = av[1];
	if (ac == 4)
	{
		mlx.r = ft_atod(av[2]);
		mlx.i = ft_atod(av[3]);
	}
	if (window(mlx))
		exit(1);
	return (0);
}
