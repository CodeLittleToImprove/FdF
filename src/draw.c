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

void	perform_bresenham(t_dot a, t_dot b, t_dot *param,
						t_BresenhamPara params)
{
	int	e2;
	// Continue iterating until the endpoint is reached
	while (a.x != b.x || a.y != b.y)
	{
//		printf("a.x = %d a.y = %d \n", a.x, a.y);
//		printf("b.x = %d b.y = %d \n", b.x, b.y);
//		printf("e2 error = %d\n",params.err);
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y,
			calculate_color(a.z, b.z));
//		printf("One Pixel done\n");
//		printf("\n");
		e2 = params.err;
		// Update the error term and x-coordinate
		if (e2 > -params.dx)
		{
//			printf("case1 :e2 > -params.dx\n");
//			printf("dy = %d\n", params.dy);
			params.err -= params.dy;
//			printf("param.err case1 = %d\n", params.err);
//			printf("sx = %d\n", params.sx);
			a.x += params.sx;
//			printf("a.x after addition = %d\n", a.x);
		}
		// Update the error term and y-coordinate
		if (e2 < params.dy)
		{
//			printf("\n");
//			printf("case2 :e2 < params.dy\n");
//			printf("dx = %d\n", params.dx);
			params.err += params.dx;
//			printf("param.err case2 = %d\n", params.err);
//			printf("sy = %d\n", params.sy);
			a.y += params.sy;
//			printf("a.y after addition = %d\n", a.y);
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
//    printf("params.dx = %d\n", params.dx);
	params.sx = compare_sign(a.x, b.x);
//    printf("params.sx = %d\n", params.sx);
	params.dy = abs(b.y - a.y);
//    printf("params.dy = %d\n", params.dy);
	params.sy = compare_sign(a.y, b.y);
//    printf("params.sy = %d\n", params.sy);
	params.err = calculate_initial_error(params.dx, params.dy);
//	printf("initial error err= %d\n", params.err);
	// Call the separate function for the Bresenham algorithm
	perform_bresenham(a, b, param, params);
}

void	draw(t_dot **matrix)
{
	int	y;
	int	x;

	y = 0;
	print_help(MATRIX_TOP_LEFT);
//    printf("is last %d\n", matrix[0][0].is_last);
	while (matrix[y] != NULL)
	{
		x = 0;
		while (!matrix[y][x].is_last)
		{
			// Draw line to the point directly below (if it exists)
			if (matrix[y + 1])
			{
//				printf("draw_line y\n");
				prepare_bresenham(matrix[y][x], matrix[y + 1][x], &MATRIX_TOP_LEFT);
//				printf("finished_line y\n\n");
			}

			// Draw line to the point directly to the right (if it exists)
//			printf("draw_line x\n");
			prepare_bresenham(matrix[y][x], matrix[y][x + 1], &MATRIX_TOP_LEFT);
//			printf("finished_line x\n\n");
			x++;
		}

		// Draw line to the last point in the row to combine end of row with first
		if (matrix[y + 1])
		{
//			printf("draw_last point\n");
			prepare_bresenham(matrix[y][x], matrix[y + 1][x], &MATRIX_TOP_LEFT);
//			printf("finished_last point\n\n");
		}
		y++; // Move to the next row
	}
//	printf("done draw\n\n");
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