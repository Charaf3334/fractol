/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:30:28 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/17 10:36:48 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks_handle(t_mlx *mlx)
{
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 4)
		mlx->zoom *= 1.1;
	else if (button == 5)
		mlx->zoom *= 0.9;
	else
		return (0);
	if (mlx->choice == 1)
		rendering(mlx, 1);
	else if (mlx->choice == 2)
		rendering(mlx, 2);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
