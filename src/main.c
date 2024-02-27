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

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 0;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr =\
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int	deal_key(int key, void *data)
{
	ft_printf("%d", key);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_dot	**matrix;

	if (argc != 2)
		ft_error_and_exit("wrong numbers of arguments");

	matrix = read_map_file(argv[1]);
//	ft_free_array(matrix);
//	matrix->mlx_ptr = mlx_init();
//	matrix->win_ptr = mlx_new_window(matrix->mlx_ptr, 1000, 1000, "FDF");
////	bresenham(10, 10, 600, 300, data);
//	matrix->zoom = 20;
//	draw(matrix);
//	mlx_key_hook(matrix->win_ptr, deal_key, NULL);
//	mlx_loop(matrix->mlx_ptr);
	if (argc == 100)
		return (-10);
}

