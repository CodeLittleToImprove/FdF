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

void	window_and_key_setup(t_data *data)
{
	mlx_key_hook(data->win_ptr, deal_key, (void *)data);
	mlx_hook(data->win_ptr, CLOSE_X_BUTTON, 0,
		destroy_window_and_exit, data);
	mlx_loop(data->mlx_ptr);
}

int	valid_key(int key)
{
	return (key == XK_plus || key == XK_KP_Add
		|| key == XK_minus || key == XK_KP_Subtract
		|| key == XK_Left || key == XK_Right
		|| key == XK_Down || key == XK_Up
		|| key == XK_i
		|| key == XK_Escape);
}

void	navigate_and_zoom(int key, t_data *data)
{
	if (key == XK_plus || key == XK_KP_Add)
		data->scale += 5;
	else if (key == XK_minus || key == XK_KP_Subtract)
		data->scale -= 5;
	else if (key == XK_Up)
		data->shift_y -= 10;
	else if (key == XK_Down)
		data->shift_y += 10;
	else if (key == XK_Left)
		data->shift_x -= 10;
	else if (key == XK_Right)
		data->shift_x += 10;
	else if (key == XK_i)
		data->isometric_on = !data->isometric_on;
	clear_image(data, BLACK);
	draw(data);
}

int	destroy_window_and_exit(t_data *data)
{
	free_mlx_stuff(data);
	exit(0);
}

int	deal_key(int key, t_data *data)
{
	if (valid_key(key))
	{
		if (key == XK_Escape)
			destroy_window_and_exit(data);
		else if (key == XK_plus || key == XK_minus
			|| key == XK_KP_Add || key == XK_KP_Subtract
			|| key == XK_Left || key == XK_Right
			|| key == XK_Down || key == XK_Up
			|| key == XK_i)
			navigate_and_zoom(key, data);
	}
	else
		ft_printf("not valid key\n");
	return (0);
}
