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

void	zoom(t_dot *a, t_dot *b, t_dot *param)
{
	// Print the values before scaling
	printf("Before scaling:\n");
	printf("Point a: x = %d, y = %d, z = %d\n", a->x, a->y, a->z);
	printf("Point b: x = %d, y = %d, z = %d\n", b->x, b->y, b->z);
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
	// Print the values after scaling
	printf("After scaling:\n");
	printf("Point a: x = %d, y = %d, z = %d\n", a->x, a->y, a->z);
	printf("Point b: x = %d, y = %d, z = %d\n", b->x, b->y, b->z);

}

void	set_param(t_dot *a, t_dot *b, t_dot *param)
{
	zoom(a, b, param);
	if (param->isometric_on)
	{
		isometric_int(&a->x, &a->y, a->z);
		isometric_int(&b->x, &b->y, b->z);
	}
	printf("After isometric convert:\n"); // z stays the same
	printf("Point a: x = %d, y = %d\n", a->x, a->y, a->z);
	printf("Point b: x = %d, y = %d\n", b->x, b->y, b->z);

	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
	printf("After shift convert:\n"); // z stays the same
	printf("Point a: x = %d, y = %d\n", a->x, a->y, a->z);
	printf("Point b: x = %d, y = %d\n", b->x, b->y, b->z);
}
