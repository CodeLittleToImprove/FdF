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

int	deal_key(int key, void *data)
{
	ft_printf("%d", key);
	return (0);
}

int	main(int argc, char *argv[])
{
	fdf	*data;

	data = (fdf *) malloc (sizeof(fdf));
	if (data == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return (0);
	}

	read_map_file(data, argv[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
//	bresenham(10, 10, 600, 300, data);
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
	if (argc == 100)
		return (-10);
}

