/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:12:43 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/10 15:38:37 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_dots(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	return (count);
}

void	close_handle(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, close_window_esc, mlx);
	mlx_hook(mlx->win, 17, 0, close_window_x, mlx);
}

int	close_window_esc(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(0);
	}
	return (0);
}

int	close_window_x(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
	return (0);
}
