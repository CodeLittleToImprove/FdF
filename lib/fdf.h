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

# define MATRIX_TOP_LEFT (matrix[0][0]) // probably not allowed


# define CLOSE_X_BUTTON 17
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
	bool		isometric_on;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}			t_dot;

typedef struct s_BresenhamPara // remember what the variable stands for
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
}	t_BresenhamPara;

//read_file.c functions
t_dot	**read_map_file(char *file_name);
t_dot	**allocate_matrix(char *file_name);
void	handle_empty_or_null_line(char *line, int fd);
int		count_lines_and_free(int fd);
int		get_dots_from_line(char *line, t_dot **matrix_of_dots, int y);

//main.c function
void	set_default_values(t_dot *param);

//draw.c functions
void	draw(t_dot **matrix);
void	prepare_bresenham(t_dot a, t_dot b, t_dot *param);
void	perform_bresenham(t_dot a, t_dot b, t_dot *param,
			t_BresenhamPara params);

//help_menu.c function
void	print_help(t_dot param);

//set_param.c functions
void	zoom(t_dot *a, t_dot *b, t_dot *param);
void	set_param(t_dot *a, t_dot *b, t_dot *param);

//draw_helper.c functions
int		calculate_initial_error(int dx, int dy);
int		calculate_color(int dot_a, int dot_b);
void	isometric_int(int *x, int *y, int z);

//key_handler.c
void	window_and_key_setup(t_dot **matrix);
int		valid_key(int key);
void	navigate_and_zoom(int key, t_dot **matrix);
int		deal_key(int key, t_dot **matrix);
int	destroy_window_and_exit(t_dot **matrix);

//ft_utils.c
void	ft_error_and_exit(char *msg);
void	handle_empty_or_null_line(char *line, int fd);
void	ft_free_array(char *array[]);
int		compare_sign(int a, int b);

#endif
