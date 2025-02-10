/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:37:55 by ctoujana          #+#    #+#             */
/*   Updated: 2025/02/10 15:37:57 by ctoujana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handling_floating_point(char *str, int i, double *ap, double *div)
{
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*ap = ((*ap) * 10) + str[i++] - '0';
		*div = (*div) * 10;
	}
}

double	ft_atod(char *str)
{
	double	result;
	double	after_point;
	double	div;
	int		i;
	int		sign;

	result = 0;
	after_point = 0;
	div = 1;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + str[i++] - '0';
	if (str[i] == '.')
		handling_floating_point(str, i, &after_point, &div);
	return (sign * (result + (after_point / div)));
}
