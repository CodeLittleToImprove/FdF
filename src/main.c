/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:44:17 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/07/04 18:07:18 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
//github version
void	set_default_values(t_data *data)
{
	data->scale = 20;
	data->z_scale = 1;
	data->isometric_on = true;
	data->win_x = 1920;
	data->win_y = 1000;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr = \
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		ft_error_and_exit("wrong numbers of arguments");
	read_map_file(argv[1], &data);
	set_default_values(&data);
	draw(&data);
	window_and_key_setup(&data);
}


