/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:03:26 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/05/10 14:03:26 by tbui-quo         ###   ########.fr       */
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
//	printf("err: %d\n", err);
	return (err);
}

int	calculate_color(int dot_a, int dot_b)
{
	int	white_hex;
	int	red_hex;
	int	cyan_hex;
	int	color;

	white_hex = 0xFFFFFF;
	red_hex = 0xfc0345;
	cyan_hex = 0x00FFFF;
	// Default color white for lines
	color = white_hex;

	// Check if either a_z or b_z is non-zero // color red for z values
	if (dot_a != 0 || dot_b != 0)
		color = red_hex;

	// Check if a_z is not equal to b_z // color cyan for outline of z
	if (dot_a != dot_b)
		color = cyan_hex;

	return (color);
}

void	isometric_int(int *x, int *y, int z)
{
	int			original_x;
	int			original_y;
	int			cos_30_degree;
	int			sin_30_degree;
	int			divisor;


	original_x = *x;
	original_y = *y;
	cos_30_degree = 866; // Approximate cos(30 degrees) ~ 0.866 (866/1000)
	sin_30_degree = 500; // Approximate sin(30 degrees) ~ 0.5 (500/1000)
	divisor = 1000;
	*x = ((original_x - original_y) * cos_30_degree) / divisor;
	*y = ((original_x + original_y) * sin_30_degree) / divisor - z;
}
