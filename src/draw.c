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

int	calculate_initial_error(int dx, int dy)
{
	int	err;
	// Initialize the decision variable based on the comparison between dx and dy.
	// The decision variable is used to decide when to increment the y-coordinate
	// (in addition to the x-coordinate) to approximate a straight line on a pixel grid.

	if (dx > dy)
		// For lines more horizontal than vertical, the initial error is set to half of dx.
		// This represents the point at which the accumulated error of drawing a straight line
		// on the pixel grid justifies moving one pixel up or down (in the y-direction).

		err = dx / 2;
	else
		// For lines more vertical than horizontal, or equally steep in both x and y directions,
		// the initial error is set to half of dy, but negated.
		// This effectively makes the algorithm more inclined to make an initial move in the y-direction,
		// reflecting the steeper ascent/descent of the line.
		err = -dy / 2;
	return (err);
}

int	calculate_color(int dot_a, int dot_b)
{
	int	color;

	// Default color white for lines
	color = 0xFFFFFF;

//	printf("dot_a: %d, dot_b: %d\n", dot_a, dot_b);
	// Check if either a_z or b_z is non-zero // color red for z values
	if (dot_a || dot_b)
		color = 0xfc0345;

	// Check if a_z is not equal to b_z // color cyan for outline of z
	if (dot_a != dot_b)
		color = 0x00FFFF;

	return (color);
}

void	isometric_int(int *x, int *y, int z)
{
	int	original_x;
	int	original_y;

	original_x = *x;
	original_y = *y;
	// Approximate cos(30 degrees) ~ 0.866 (866/1000) and sin(30 degrees) ~ 0.5 (500/1000)
	*x = ((original_x - original_y) * 866) / 1000;
	*y = ((original_x + original_y) * 500) / 1000 - z;
}

void	perform_bresenham(t_dot a, t_dot b, t_dot *param,
						t_BresenhamPara params)
{
	int	e2;
	// Continue iterating until the endpoint is reached
	while (a.x != b.x || a.y != b.y)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y,
			calculate_color(a.z, b.z));

		e2 = params.err;
		// Update the error term and x-coordinate
		if (e2 > -params.dx)
		{
			params.err -= params.dy;
			a.x += params.sx;
		}
		// Update the error term and y-coordinate
		if (e2 < params.dy)
		{
			params.err += params.dx;
			a.y += params.sy;
		}
	}
}

void	prepare_bresenham(t_dot a, t_dot b, t_dot *param)
{
	t_BresenhamPara	params;

	set_param(&a, &b, param);
	// Convert to isometric coordinates before anything else
//	isometric_int(&a.x, &a.y, a.z);
//	isometric_int(&b.x, &b.y, b.z);
	params.dx = abs(b.x - a.x);
	params.sx = compare_sign(a.x, b.x);
	params.dy = abs(b.y - a.y);
	params.sy = compare_sign(a.y, b.y);
	params.err = calculate_initial_error(params.dx, params.dy);

	// Call the separate function for the Bresenham algorithm
	perform_bresenham(a, b, param, params);
}

//void	bresenham(t_dot a, t_dot b, t_dot *param) //do keybindings // short version which is more readable than the norminette comfort
//{
//	int	dx;
//	int	sx;
//	int	dy;
//	int	sy;
//	int	err;
//
//	set_param(&a, &b, param);
//	// Convert to isometric coordinates before anything else
//	isometric_int(&a.x, &a.y, a.z);
//	isometric_int(&b.x, &b.y, b.z);
//	dx = abs(b.x - a.x);
//	sx = compare_sign(a.x, b.x);
//	dy = abs(b.y - a.y);
//	sy = compare_sign(a.y, b.y);
//	err = calculate_initial_error(dx, dy);
//
//
//	while (1)
//	{
//		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y,
//			calculate_color(a.z, b.z));
//		// Check if the endpoint has been reached
//		if (a.x == b.x && a.y == b.y)
//			break;
//		int e2 = err;
//		// Update the error term and x-coordinate
//		if (e2 > -dx) {
//			err -= dy;
//			a.x += sx;
//		}
//		// Update the error term and y-coordinate
//		if (e2 < dy) {
//			err += dx;
//			a.y += sy;
//		}
//	}
//}

//void	bresenham(t_dot a, t_dot b, t_dot *param) //do keybindings // short version // no comments
//{
//	int	dx;
//	int	sx;
//	int	dy;
//	int	sy;
//	int	err;
//
//	set_param(&a, &b, param);
//	isometric_int(&a.x, &a.y, a.z);
//	isometric_int(&b.x, &b.y, b.z);
//	dx = abs(b.x - a.x);
//	sx = compare_sign(a.x, b.x);
//	dy = abs(b.y - a.y);
//	sy = compare_sign(a.y, b.y);
//	err = calculate_initial_error(dx, dy);
//
//	while (1)
//	{
//		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y,
//			calculate_color(a.z, b.z));
//		if (a.x == b.x && a.y == b.y)
//			break;
//		int e2 = err;
//		if (e2 > -dx)
//		{
//			err -= dy;
//			a.x += sx;
//		}
//		if (e2 < dy)
//		{
//			err += dx;
//			a.y += sy;
//		}
//	}
//}

//void bresenham(t_dot a, t_dot b, t_dot *param) // need to rewrite this with less variable use // do keybindings // long version
//{
//	int	x0;
//	int	y0;
//	int	x1;
//	int	y1;
//	int	dx;
//	int	dy;
//	int	err;
//	int	sx;
//	int	sy;
//	int	e2;
//	int	color;
//
//
//	set_param(&a, &b, param);
//	// Convert to isometric coordinates before anything else
//	isometric_int(&a.x, &a.y, a.z);
//	isometric_int(&b.x, &b.y, b.z);
//	x0 = a.x;
//	y0 = a.y;
//	x1 = b.x;
//	y1 = b.y;
//	dx = abs(x1 - x0);
//	sx = compare_sign(x0, x1);
//	dy = abs(y1 - y0);
//	sy = compare_sign(y0, y1);
//	err = calculate_initial_error(dx, dy);
//	color = calculate_color(a.z, b.z);
//
//	while (1)
//	{
//		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x0, y0, color);
//		// Check if the endpoint has been reached
//		if (x0 == x1 && y0 == y1)
//			break ;
//		e2 = err;
//		// Update the error term and x-coordinate
//		if (e2 > -dx)
//		{
//			err -= dy;
//			x0 += sx;
//		}
//		// Update the error term and y-coordinate
//		if (e2 < dy)
//		{
//			err += dx;
//			y0 += sy;
//		}
//	}
//}

//void bresenham(t_dot a, t_dot b, t_dot *param) // need to rewrite this with less variable use // do keybindings // is working
//{
//	int	x0;
//	int	y0;
//	int	x1;
//	int	y1;
//	int	dx;
//	int	dy;
//	int	err;
//	int	sx;
//	int	sy;
//	int	e2;
//	int	color;
//
//
//	set_param(&a, &b, param);
//	// Convert to isometric coordinates before anything else
//	isometric_int(&a.x, &a.y, a.z);
//	isometric_int(&b.x, &b.y, b.z);
//	x0 = a.x;
//	y0 = a.y;
//	x1 = b.x;
//	y1 = b.y;
//	dx = abs(x1 - x0);
//	sx = compare_sign(x0, x1);
//	dy = abs(y1 - y0);
//	sy = compare_sign(y0, y1);
//	err = calculate_initial_error(dx, dy);
//	color = calculate_color(a.z, b.z);
//
//	while (1)
//	{
//		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x0, y0, color);
//		// Check if the endpoint has been reached
//		if (x0 == x1 && y0 == y1)
//			break ;
//		e2 = err;
//		// Update the error term and x-coordinate
//		if (e2 > -dx)
//		{
//			err -= dy;
//			x0 += sx;
//		}
//		// Update the error term and y-coordinate
//		if (e2 < dy)
//		{
//			err += dx;
//			y0 += sy;
//		}
//	}
//}

void	draw(t_dot **matrix)
{
	int	y;
	int	x;

	y = 0;
	print_help(MATRIX_TOP_LEFT);
	while (matrix[y] != NULL)
	{
		x = 0;
		while (!matrix[y][x].is_last)
		{
			// Draw line to the point directly below (if it exists)
			if (matrix[y + 1])
				prepare_bresenham(matrix[y][x], matrix[y + 1][x], &MATRIX_TOP_LEFT);

			// Draw line to the point directly to the right (if it exists)
			prepare_bresenham(matrix[y][x], matrix[y][x + 1], &MATRIX_TOP_LEFT);
		x++;
		}

		// Draw line to the last point in the row to combine end of row with first
		if (matrix[y + 1])
			prepare_bresenham(matrix[y][x], matrix[y + 1][x], &MATRIX_TOP_LEFT);


	y++; // Move to the next row
	}
}

//void	draw(t_dot **matrix) // working version
//{
//	int	y;
//	int	x;
//
//	y = 0;
//	while (matrix[y] != NULL)
//	{
//		x = 0;
//		while (!matrix[y][x].is_last)
//		{
//			// Draw line to the point directly below (if it exists)
//			if (matrix[y + 1])
//				bresenham(matrix[y][x], matrix[y + 1][x], &MATRIX_TOP_LEFT);
//
//			// Draw line to the point directly to the right (if it exists)
//			bresenham(matrix[y][x], matrix[y][x + 1], &MATRIX_TOP_LEFT);
//			x++;
//		}
//
//		// Draw line to the last point in the row to combine end of row with first
//		if (matrix[y + 1])
//			bresenham(matrix[y][x], matrix[y + 1][x], &MATRIX_TOP_LEFT);
//
//
//		y++; // Move to the next row
//	}
//}