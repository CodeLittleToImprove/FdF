/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:51:53 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/02/28 18:51:53 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	zoom(t_dot *a, t_dot *b, t_data *data)
{
	// printf("Before scaling:\n");
	// printf("Point a: x = %d, y = %d, z = %d\n", a->x, a->y, a->z);
	// printf("Point b: x = %d, y = %d, z = %d\n", b->x, b->y, b->z);
	a->x *= data->scale;
	a->y *= data->scale;
	b->x *= data->scale;
	b->y *= data->scale;
	a->z *= data->z_scale;
	b->z *= data->z_scale;
	// printf("After scaling:\n");
	// printf("Point a: x = %d, y = %d, z = %d\n", a->x, a->y, a->z);
	// printf("Point b: x = %d, y = %d, z = %d\n", b->x, b->y, b->z);
}

void	set_param(t_dot *a, t_dot *b, t_data *data)
{
	zoom(a, b, data);
	// printf("Pre isometric convert:\n"); // z stays the same
	// printf("Point a: x = %d, y = %d\n", a->x, a->y);
	// printf("Point b: x = %d, y = %d\n", b->x, b->y);
	if (data->isometric_on)
	{
		isometric_int(&a->x, &a->y, a->z);
		isometric_int(&b->x, &b->y, b->z);
	}
	// printf("After isometric convert:\n"); // z stays the same
	// printf("Point a: x = %d, y = %d\n", a->x, a->y);
	// printf("Point b: x = %d, y = %d\n", b->x, b->y);
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
//	printf("After shift convert:\n"); // z stays the same
//	printf("Point a: x = %d, y = %d\n", a->x, a->y);
//	printf("Point b: x = %d, y = %d\n", b->x, b->y);
}
