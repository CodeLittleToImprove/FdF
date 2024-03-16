/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:42:59 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/02/28 18:42:59 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#include <X11/keysym.h>

int	valid_key(int key)
{
	return (key == XK_plus || key == XK_KP_Add
		|| key == XK_minus || key == XK_KP_Subtract
		|| key == XK_Left || key == XK_Right
		|| key == XK_Down || key == XK_Up
		|| key == XK_Escape);
}

void	navigate_and_zoom(int key, t_dot **matrix)
{
	mlx_clear_window(MATRIX_TOP_LEFT.mlx_ptr, MATRIX_TOP_LEFT.win_ptr);
	if (key == XK_plus || key == XK_KP_Add)
	{
		MATRIX_TOP_LEFT.scale += 5;
		printf("plus pressed\n");
	}
	else if (key == XK_minus || key == XK_KP_Subtract)
	{
		MATRIX_TOP_LEFT.scale -= 5;
		printf("minus pressed\n");
	}
	else if (key == XK_Up)
	{
		MATRIX_TOP_LEFT.shift_y -= 10;
		printf("up pressed\n");
	}
	else if (key == XK_Down)
	{
		MATRIX_TOP_LEFT.shift_y += 10;
		printf("down pressed\n");
	}
	else if (key == XK_Left)
	{
		MATRIX_TOP_LEFT.shift_x -= 10;
		printf("left pressed\n");
	}
	else if (key == XK_Right)
	{
		MATRIX_TOP_LEFT.shift_x += 10;
		printf("right pressed\n");
	}

	draw(matrix);
}

int	deal_key(int key, t_dot **matrix)
{
	if (valid_key(key))
	{
		ft_printf("%d\n", key);
		if (key == XK_Escape)
		{
			mlx_destroy_window(MATRIX_TOP_LEFT.mlx_ptr,
				MATRIX_TOP_LEFT.win_ptr);
//		free(matrix);
			exit(0);
		}
		else if (key == XK_plus || key == XK_minus
			|| key == XK_KP_Add || key == XK_KP_Subtract
			|| key == XK_Left || key == XK_Right
			|| key == XK_Down || key == XK_Up)
			navigate_and_zoom(key, matrix);
	}
	else
		ft_printf("not valid key\n");
	return (0);
}



//int	deal_key(int key, t_dot **matrix) working version
//{
//	ft_printf("%d\n", key);
//	return (0);
//}