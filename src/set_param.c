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
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
}

void	set_param(t_dot *a, t_dot *b, t_dot *param)
{
	zoom(a, b, param);
	if (param->isometric_on)
	{
		isometric_int(&a->x, &a->y, a->z);
		isometric_int(&b->x, &b->y, b->z);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}
