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
# define BLACK 0x000000
# define ERR_INVALID_FILE_EXT "Error: Invalid file extension. Only .fdf files are allowed \n"

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_dot
{
	int			x;
	int			y;
	int			z;
	int			is_last;
}			t_dot;

typedef struct s_data
{
	int			win_x;
	int			win_y;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	bool		isometric_on;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_dot		**matrix;
}		t_data;

typedef struct s_BresenhamPara // Struct for Bresenham's line algorithm parameters
{
	int	dx; // Delta X: Absolute difference in x-coordinates between the two points
	int	sx; // Step X: Direction of movement in x (1 for positive direction, -1 for negative)
	int	dy; // Delta Y: Absolute difference in y-coordinates between the two points
	int	sy; // Step Y: Direction of movement in y (1 for positive direction, -1 for negative)
	int	err; // Error term: Determines when to step in y as you iterate in x, or vice versa
}	t_BresenhamPara;

//draw.c functions
void		my_pixel_put(t_dot a, t_dot b, t_data *data);
void		prepare_bresenham(t_dot a, t_dot b, t_data *data);
void		perform_bresenham(t_dot a, t_dot b, t_data *data,
				t_BresenhamPara params);
void		clear_image(t_data *data, int color);
void		draw(t_data *data);

//draw_helper.c functions
int			calculate_initial_error(int dx, int dy);
int			calculate_color(int dot_a, int dot_b);
void		isometric_int(int *x, int *y, int z);

//help_menu.c functions
void		print_help(t_data *data);

//key_handler.c functions
void		window_and_key_setup(t_data *data);
int			valid_key(int key);
void		navigate_and_zoom(int key, t_data *data);
int			destroy_window_and_exit(t_data *data);
int			deal_key(int key, t_data *data);

//main.c functions
void		set_default_values(t_data *data);

//read_file.c functions
size_t		count_values_in_line_and_free(char *file_name);
size_t		count_lines_in_file_and_free(char *filename);
int			get_dots_from_line(char *line, t_dot **matrix_of_dots, int y);
t_dot		**allocate_matrix(char *file_name);
void		read_map_file(char *file_name, t_data *data);

//read_file_utils.c functions
void		handle_empty_or_null_line(char *line, int fd);
int			safe_str_to_int(const char *nbr_str);
bool		is_fdf_file(const char *filename);

//set_param.c functions
void		zoom(t_dot *a, t_dot *b, t_data *data);
void		set_param(t_dot *a, t_dot *b, t_data *data);

//utils.c functions
void		ft_error_and_exit(char *msg);
void		free_matrix(t_data *data);
void		free_mlx_stuff(t_data *data);
void		print_matrix_of_dots(t_dot **matrix_of_dots);
#endif
