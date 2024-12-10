/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:03:16 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/02/27 18:03:16 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_error_and_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	free_mlx_stuff(t_data *data)
{
	if (data->img.img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = NULL;
	}
	if (data->win_ptr != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	free_matrix(data);
}

void	free_matrix(t_data *data) // new
{
	size_t	total_rows;
	size_t	row_index;

	total_rows = 0;
	row_index = 0;
	if (data->matrix == NULL)
		return ;
	while (data->matrix [total_rows] != NULL)
		total_rows++;
	total_rows--;
	while (row_index <= total_rows)
	{
		free(data->matrix [row_index]);
		row_index++;
	}
	free(data->matrix);
}

static void print_dot(t_dot dot)
{
	printf("Dot:\n");
	printf("  x: %d\n", dot.x);
	printf("  y: %d\n", dot.y);
	printf("  z: %d\n", dot.z);
	printf("  is_last: %d\n", dot.is_last);
}

void	print_matrix(t_data *data)
{
	int y = 0;
	while (data->matrix[y] != NULL)
	{
		int x = 0;
		while (!data->matrix[y][x].is_last)
		{
			printf("Dot at [%d][%d]:\n", y, x);
			print_dot(data->matrix[y][x]);
			x++;
		}
		printf("Dot at [%d][%d]:\n", y, x);
		print_dot(data->matrix[y][x]);
		y++;
	}
}
