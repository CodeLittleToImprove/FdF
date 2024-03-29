/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:44:37 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/08/22 14:44:37 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef FDF_H
//# define FDF_H
//
//# include "libft/libft.h"
//# include "ft_printf/ft_printf.h"
//# include "ft_printf/get_next_line/get_next_line.h"
//
//# include "mlx_linux/mlx.h"
//# include <stdlib.h>
//# include <unistd.h>
//# include <stdio.h>
//# include <fcntl.h>
//# include <math.h>
//# include <stdbool.h>
//
////typedef struct	s_data {
////	void	*img;
////	char	*addr;
////	int		bits_per_pixel;
////	int		line_length;
////	int		endian;
////}				t_data;
//
//typedef struct s_fdf
//{
//	int	width;
//	int	height;
//	int	**z_matrix;
//	int	zoom;
//	int	color;
//
//	void	*mlx_ptr;
//	void	*win_ptr;
//}			fdf;
//
//void	read_map_file(fdf *data, char *file_name);
//void	isometric(int *x, int *y, int z);
////void isometric(float *x, float *y, float z);
////void	bresenham(float x, float y, float x1, float y1, fdf *data);
//void	bresenham(int x, int y, int x1, int y1, fdf *data);
//void	draw(fdf *data);
//
//#endif