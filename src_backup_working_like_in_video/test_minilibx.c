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

#include "fdf.h"

//int main(void)
//{
//	void *mlx_ptr;
//	void *win_ptr;
//
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "MiniLibX Test");
//	(void)win_ptr;  // Silence the "unused variable" warning
//
//	mlx_loop(mlx_ptr);
//
//	return (0);
//}
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

//void my_mlx_pixel_put(t_data *data, int x, int y, int size, int color)
//{
//	char *dst;
//
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			dst = data->addr + ((y + i) * data->line_length + (x + j) * (data->bits_per_pixel / 8));
//			*(unsigned int *)dst = color;
//		}
//	}
//}


//int main(void)
//{
//	void *mlx;
//	void *mlx_win;
//	t_data img;
//
//	// Initialize the MiniLibX
//	mlx = mlx_init();
//
//	// Create a window
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//
//	// Create an image
//	img.img = mlx_new_image(mlx, 1920, 1080);
//
//	// Get image information
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//
//	// Put a red pixel at coordinates (5, 5)
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//
//	//make a line
//	for (int i = 0; i < 1920; ++i)
//	{
//		my_mlx_pixel_put(&img,0 + i, 0, 0x00FF0000);
//	}
//	// Put the image on the window
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//
//	// Enter the MiniLibX event loop
//	mlx_loop(mlx);
//}
