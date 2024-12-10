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

void	my_pixel_put(t_dot a, t_dot b, t_data *data)
{
	int	offset;
	int	color;

	color = calculate_color(a.z, b.z);
	if (a.x < 0 || a.x >= data->win_x || a.y < 0 || a.y >= data->win_y)
		return ;
	offset = (data->img.line_len * a.y)
		+ (a.x * (data->img.bits_per_pixel / 8));
	*((unsigned int *)(offset + data->img.img_pixels_ptr)) = color;
}

void	prepare_bresenham(t_dot a, t_dot b, t_data *data)
{
	t_BresenhamPara	params;

	set_param(&a, &b, data);
	params.dx = ft_abs(b.x - a.x);
	//printf("params.dx = %d\n", params.dx);
	params.sx = ft_compare_sign(a.x, b.x);
	//printf("params.sx = %d\n", params.sx);
	params.dy = ft_abs(b.y - a.y);
	//printf("params.dy = %d\n", params.dy);
	params.sy = ft_compare_sign(a.y, b.y);
	//printf("params.sy = %d\n", params.sy);
	params.err = calculate_initial_error(params.dx, params.dy);
	//	printf("initial error err= %d\n", params.err);
	perform_bresenham(a, b, data, params);
}

void	perform_bresenham(t_dot a, t_dot b, t_data *data,
						t_BresenhamPara params)
{
	int	e2;

	while (a.x != b.x || a.y != b.y) // Loop until the current point reaches the end point
	{
		my_pixel_put(a, b, data);
		e2 = params.err; // Store the current error value to decide the next step
		// Check if the error allows a step in the x-direction
		if (e2 > -params.dx)
		{
			params.err -= params.dy; // Adjust the error for a horizontal step
			a.x += params.sx; // Move in the x-direction based on the step direction (sx)
		}
		// Check if the error allows a step in the y-direction
		if (e2 < params.dy)
		{
			params.err += params.dx;
			a.y += params.sy;
		}
	}
}

void	clear_image(t_data *data, int color)
{
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	// start from top left
	while (y < data->win_y)
	{
		x = 0;
		while (x < data->win_x)
		{
			// Calculate the memory address of the pixel at (x, y) to find exactly which pixel to change
			pixel = data->img.img_pixels_ptr + (y * data->img.line_len + x * (data->img.bits_per_pixel / 8));
			*(unsigned int *)pixel = color; // pixel is cast to unsigned int * so that it can be treated as a 4-byte (32-bit) integer
			x++;
		}
		y++;
	}
}

void	draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->matrix[y] != NULL)
	{
		x = 0;
		while (!data->matrix[y][x].is_last)
		{
			// If there is a row below the current one, draw a line to the corresponding point below
			if (data->matrix[y + 1])
				prepare_bresenham(data->matrix[y][x], data->matrix[y + 1][x], data);
			// Draw a line to the next point in the same row
			prepare_bresenham(data->matrix[y][x], data->matrix[y][x + 1], data);
			x++;
		}
		// After processing all points in the row, check the last column
		// If there's a row below, draw a line to the corresponding point below
		if (data->matrix[y + 1])
			prepare_bresenham(data->matrix[y][x], data->matrix[y + 1][x], data);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	print_help(data);
}

