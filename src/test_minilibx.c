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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_pixels_ptr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(void)
{
	void *mlx;
	void *mlx_win;
	t_img img;

	// Initialize the MiniLibX
	mlx = mlx_init();

	// Create a window
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

	// Create an image
	img.img_ptr = mlx_new_image(mlx, 1920, 1080);

	// Get image information
	img.img_pixels_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len, &img.endian);

	// Put a red pixel at coordinates (5, 5)
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);

//	//make a horizontal line
//	for (int i = 0; i < 1920; ++i)
//	{
//		my_mlx_pixel_put(&img,0 + i, 0, 0x00FF0000);
//	}
//	// make vertical line
//	for (int i = 0; i < 1080; ++i)
//	{
//		my_mlx_pixel_put(&img,0, 0 + i, 0x00FF0000);
//	}
	for (int i = 0; i < 1920; ++i)
	{
		int j = 0; // Reset `j` for each column
		while (j < 1080)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000); // Paint pixel (i, j) red
			++j;
		}
	}

	// Put the image on the window
	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);

	// Enter the MiniLibX event loop
	mlx_loop(mlx);
}
