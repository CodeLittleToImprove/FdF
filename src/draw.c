/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:02:54 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/02/20 18:02:54 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

//void	bresenham(float x, float y, float x1, float y1, fdf *data) // need rewrite for using ints instead of floats
//{
//	float	x_step;
//	float	y_step;
//	int		max;
//
//	x_step = x1 - x;
//	y_step = y1 - y;
//	max = ft_max(abs(x_step), abs(y_step));
//	x_step = x_step / max;
//	y_step = y_step / max;
//	while ((int)(x - x1) || (int)(y - y1))
//	{
//		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
//		x = x + x_step;
//		y = y + y_step;
//	}
//}

void	bresenham(int x, int y, int x2, int y2, fdf *data)
{
	int	dx;
	int	dy;
	int	p;
	int	step_y;

	dx = abs(x2 - x);
	dy = abs(y2 - y);
	p = 2 * dy - dx;
	if (y2 > y)
		step_y = 1;
	else
		step_y = -1;
	while (x <= x2)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * (dy - dx);
			y += step_y;
		}
	}
}

