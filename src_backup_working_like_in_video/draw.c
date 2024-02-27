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

//void isometric(float *x, float *y, float z)
//{
//	*x = (*x - *y) * cos(0.8);
//	*y = (*x + *y) * sin(0.8) - z;
//}
//
//void	bresenham(float x, float y, float x1, float y1, fdf *data) // need rewrite for using ints instead of floats
//{
//	float	x_step;
//	float	y_step;
//	int		max;
//	int		z;
//	int		z1;
//	z = data->z_matrix[(int)y][(int)x];
//	z1 = data->z_matrix[(int)y1][(int)x1];
////-------zooom-----------
//x *= data->zoom;
//y *= data->zoom;
//x1 *= data->zoom;
//y1 *= data->zoom;
////-------color------------
//	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
//
//
//
////-------3d------------
//	isometric(&x, &y, z);
//	isometric(&x1,&y1,z1);
//
////-------shift----------------
//x += 150;
//y += 150;
//x1 += 150;
//y1 += 150;
//
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

//void	bresenham(int x, int y, int x2, int y2, fdf *data) // does not handle vertical ligns at all old my version
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


void isometric(int *x, int *y, int z)
{
	double angle = 0.8;  // Angle in radians
	double radian_cos = cos(angle);
	double radian_sin = sin(angle);

	// Scale the inputs to fit within the range of sine and cosine functions
	double scaled_x = (double)(*x);
	double scaled_y = (double)(*y);
	double scaled_z = (double)(z);

	// Perform the isometric transformation using scaled values
	*x = (int)((scaled_x - scaled_y) * radian_cos);
	*y = (int)((scaled_x + scaled_y) * radian_sin - scaled_z);
	printf("x: %d, y: %d\n", *x, *y);
}

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

void	bresenham(int x, int y, int x2, int y2, fdf *data) // look for a different way
{
	int x0;
	int y0;
	int dx;
	int dy;
	int err;
	int x2_zoomed;
	int sx;
	int sy;
	int e2;
	int z;
	int z1;



	// Apply zoom
	x0 = x * data->zoom;
	y0 = y * data->zoom;
	x2_zoomed = x2 * data->zoom;
	int y2_zoomed = y2 * data->zoom;
	// color------------------------
	z = data->z_matrix[(int) y][(int) x];
	z1 = data->z_matrix[(int) y2][(int) x2];
	data->color = (z) ? 0xe80c0c : 0xffffff;

	//-----------3D----------------------------
//	isometric(&x0, &y0, z);
//	isometric(&x2_zoomed, &y2_zoomed, z1);

//--------------shift-------------------------
//	x0 += 150;
//	y0 += 150;
//	x2_zoomed += 150;
//	y2_zoomed += 150;

	// Calculate deltas
	dx = abs(x2 - x);
	dy = abs(y2 - y);



	// Determine the sign of the increments
	sx = (x < x2) ? 1 : -1;
	sy = (y < y2) ? 1 : -1;

	err = (dx > dy) ? dx / 2 : -dy / 2;  // Initialize the error term


	while (x0 != x2_zoomed)
	{  // Iterate until reaching the end point
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color);  // Draw the pixel

		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}

	if (dx == 0)
	{ // If dx is 0, the line is vertical
		draw_vertical_line(x, y, x2, y2, data); // Handle the vertical line separately
	}
}

void	draw(fdf *data)
	{
		int x;
		int y;

		y = 0;
		while (y < data->height)
		{
			x = 0;
			while (x < data->width)
			{
				if (x < data->width - 1)
					bresenham(x, y, x + 1, y, data);
				if (y < data->height - 1)
					bresenham(x, y, x, y + 1, data);
				x++;
			}
			y++;
		}
	}
