/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:23:51 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/10 17:09:02 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	double	zoom;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		choice;
	char	*title;
	double	r;
	double	i;
}	t_mlx;

int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	put_pixel(t_mlx *data, int x, int y, int color);
void	close_handle(t_mlx *mlx);
int		close_window_esc(int keycode, t_mlx *mlx);
int		close_window_x(t_mlx *mlx);
double	get_coordinates(int pixel, double max, double min, int size);
void	draw_mandelbrot(t_mlx *mlx);
int		iterate_mandelbrot(double real, double imag, int iterations);
void	draw_julia(t_mlx *mlx, double r, double i);
int		iterate_julia(double real, double imag, double re, double im);
int		check_sign(char *str);
int		check_char(char *str);
void	check(char **av, int i);
void	error_message(int n);
int		check_args(int ac, char **av);
double	ft_atod(char *str);
void	rendering(t_mlx *mlx, int choice);
int		mouse_hook(int button, int x, int y, t_mlx *mlx);
void	hooks_handle(t_mlx *mlx);
int		check_dots(char *str);

#endif