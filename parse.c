/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:53:52 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/10 16:55:16 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_point(char *str, int j)
{
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j + 1] == '.' && (str[j + 2] >= '0' && str[j + 2] <= '9'))
			return (0);
	}
	else if (str[j] == '.' && (str[j + 1] >= '0' && str[j + 1] <= '9'))
		return (0);
	return (1);
}

int	check_sign(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+'))
		return (1);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (1);
	j = i;
	if (str[j + 1] == '\0' && !(str[j] >= '0' && str[j] <= '9'))
		return (1);
	while (str[j])
	{
		if (j == i && !(str[j] >= '0' && str[j] <= '9')
			&& !(str[j + 1] >= '0' && str[j + 1] <= '9'))
			handle_point(str, j);
		if (j > i && (str[j] == '-' || str[j] == '+'))
			return (1);
		j++;
	}
	return (0);
}

int	check_char(char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = check_dots(str);
	if (count > 1)
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	j = i;
	while (str[j])
	{
		if ((str[j] < '0' || str[j] > '9') && str[j] != '-' && str[j] != '+'
			&& str[j] != '.')
			return (1);
		j++;
	}
	return (0);
}

void	check(char **av, int i)
{
	if (av[i][0] == '\0')
	{
		write (2, "Error!\n", 8);
		error_message(1);
	}
	if (check_char(av[i]) || check_sign(av[i]))
	{
		write (2, "Error!\n", 8);
		error_message(1);
	}
}

int	check_args(int ac, char **av)
{	
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		return (1);
	else if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		check(av, 2);
		check(av, 3);
		return (2);
	}
	error_message(0);
	return (0);
}
