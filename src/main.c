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
void	set_default_values(t_dot *param)
{
	param->scale = 20; // zoom in and out
	param->z_scale = 1;
	param->isometric_on = true;
	param->win_x = 1920;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = \
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int	main(int argc, char *argv[])
{
	t_dot	**matrix;

	if (argc != 2)
		ft_error_and_exit("wrong numbers of arguments");
	matrix = read_map_file(argv[1]);
	set_default_values(&MATRIX_TOP_LEFT);
	draw(matrix);
	window_and_key_setup(matrix);
//	mlx_key_hook(MATRIX_TOP_LEFT.win_ptr, deal_key, matrix);
//	mlx_hook(MATRIX_TOP_LEFT.win_ptr, CLOSE_X_BUTTON, 0, destroy_window_and_exit, matrix);
//	mlx_loop(MATRIX_TOP_LEFT.mlx_ptr);
}

