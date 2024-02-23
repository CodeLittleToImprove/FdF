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
//
////-------zooom-----------
//x *= data->zoom;
//y *= data->zoom;
//x1 *= data->zoom;
//y1 *= data->zoom;
//	x_step = x1 - x;
//	y_step = y1 - y;
//	max = ft_max(abs(x_step), abs(y_step));
//	x_step = x_step / max;
//	y_step = y_step / max;
//	while ((int)(x - x1) || (int)(y - y1))
//	{
////		printf("x = %d y = %d \n",x, y);
//		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
//		x = x + x_step;
//		y = y + y_step;
//	}
//}

//void	bresenham(int x, int y, int x2, int y2, fdf *data) // does not handle vertical ligns at all
//{
//	int	dx;
//	int	dy;
//	int	p;
//	int	step_y;
//
//	//-------zooom-----------
//	x *= data->zoom;
//	y *= data->zoom;
//	x2 *= data->zoom;
//	y2 *= data->zoom;
//
//	dx = abs(x2 - x);
//	dy = abs(y2 - y);
//	p = 2 * dy - dx;
//	if (y2 > y)
//		step_y = 1;
//	else
//		step_y = -1;
//	while (x <= x2)
//	{
////		printf("x = %d y = %d \n",x, y);
//		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
//		x++;
//		if (p < 0)
//			p += 2 * dy;
//		else
//		{
//			p += 2 * (dy - dx);
//			y += step_y;
//		}
//	}
//}

void draw_vertical_line(int x, int y, int x2, int y2, fdf *data) {
	int step_y = (y < y2) ? 1 : -1;  // Determine the direction to increment y
	int dy = abs(y2 - y);  // Calculate the absolute difference in y
	int x0 = x * data->zoom;  // Apply zoom
	int y0 = y * data->zoom;
	int y2_zoomed = y2 * data->zoom;

	while (y0 != y2_zoomed) {  // Iterate until reaching the end point
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xFFFFFF);  // Draw the pixel
		y0 += step_y;  // Increment or decrement y
	}
}

//void bresenham(int x, int y, int x2, int y2, fdf *data) {
//	// Apply zoom
//	int x0 = x * data->zoom;
//	int y0 = y * data->zoom;
//	int x2_zoomed = x2 * data->zoom;
//
//	// Calculate deltas
//	int dx = abs(x2 - x);
//	int dy = abs(y2 - y);
//
//	// Determine the sign of the increments
//	int sx = (x < x2) ? 1 : -1;
//	int sy = (y < y2) ? 1 : -1;
//
//	int err = (dx > dy) ? dx / 2 : -dy / 2;  // Initialize the error term
//
//	while (x0 != x2_zoomed) {  // Iterate until reaching the end point
//		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xFFFFFF);  // Draw the pixel
//
//		int e2 = err;
//		if (e2 > -dx) {
//			err -= dy;
//			x0 += sx;
//		}
//		if (e2 < dy) {
//			err += dx;
//			y0 += sy;
//		}
//	}
//
//	if (dx == 0) { // If dx is 0, the line is vertical
//		draw_vertical_line(x, y, x2, y2, data); // Handle the vertical line separately
//	}
//}

void bresenham(int x, int y, int x2, int y2, fdf *data) // look for a different way
{
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int	err;
	int	x2_zoomed;
	int	sx;
	int	sy;
	int	e2;

	// Apply zoom
	x0 = x * data->zoom;
	y0 = y * data->zoom;
	x2_zoomed = x2 * data->zoom;

	// Calculate deltas
	dx = abs(x2 - x);
	dy = abs(y2 - y);

	// Determine the sign of the increments
	sx = (x < x2) ? 1 : -1;
	sy = (y < y2) ? 1 : -1;

	err = (dx > dy) ? dx / 2 : -dy / 2;  // Initialize the error term

	while (x0 != x2_zoomed) {  // Iterate until reaching the end point
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xFFFFFF);  // Draw the pixel

		e2 = err;
		if (e2 > -dx) {
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy) {
			err += dx;
			y0 += sy;
		}
	}

	if (dx == 0) { // If dx is 0, the line is vertical
		draw_vertical_line(x, y, x2, y2, data); // Handle the vertical line separately
	}
}


void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			bresenham(x, y, x + 1, y, data);
			bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
