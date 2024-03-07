/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:05:49 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/02/27 18:05:49 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/ft_printf/get_next_line/get_next_line.h"

# include "../lib/mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define MATRIX_TOP_LEFT matrix[0][0]
//typedef struct	s_data {
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//}				t_data;

typedef struct s_dot
{
	int			x;
	int			y;
	int			z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
//	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}			t_dot;

typedef struct s_BresenhamPara
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
}	t_BresenhamPara;

t_dot	**read_map_file(char *file_name);
t_dot	**allocate_matrix(char *file_name);
void	isometric(int *x, int *y, int z);
//void isometric(float *x, float *y, float z);
//void	bresenham(float x, float y, float x1, float y1, t_dot *data);
//void	bresenham(int x, int y, int x1, int y1, t_dot *data);
void	draw(t_dot **matrix);
int		deal_key(int key, t_dot **matrix);
void	set_param(t_dot *a, t_dot *b, t_dot *param);
void	ft_error_and_exit(char *msg);
void	ft_free_array(char *array[]);
#endif
