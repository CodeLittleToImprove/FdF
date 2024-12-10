/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:07:28 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/02/17 19:07:28 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

size_t	count_values_in_line_and_free(char *file_name)
{
	int		fd;
	char	*line;
	size_t	values_in_line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error_and_exit("file does not exist or no permission");
	line = get_next_line(fd);
	if (line == NULL)
		handle_empty_or_null_line(line, fd);
	values_in_line = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (values_in_line);
}

size_t	count_lines_in_file_and_free(char *file_name)
{
	size_t		lines_in_file;
	int			fd;
	char		*line;

	lines_in_file = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		lines_in_file++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines_in_file);
}

int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char		**dots;
	int			x;
	int			z_value;

	dots = ft_split(line, ' ');
	x = 0;
	z_value = 0;
	while (dots[x] != NULL)
	{
		z_value = safe_str_to_int(dots[x]);
		matrix_of_dots[y][x].z = z_value;
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	if (x > 0)
		matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**allocate_matrix(char *file_name)
{
	t_dot	**allocated_matrix;
	size_t	x;
	size_t	y;

	x = count_values_in_line_and_free(file_name);
	y = count_lines_in_file_and_free(file_name);
	allocated_matrix = (t_dot **) ft_calloc(sizeof(t_dot *), (y + 1));
	if (!allocated_matrix)
		ft_error_and_exit("Memory allocation failed");
	while (y > 0)
	{
		allocated_matrix[y - 1] = (t_dot *) ft_calloc(sizeof(t_dot), x);
		y--;
	}
	return (allocated_matrix);
}

void	read_map_file(char *file_name, t_data *data)
{
	int		y;
	int		fd;
	char	*line;
	char	*next_line;

	if (!is_fdf_file(file_name))
		ft_error_and_exit(ERR_INVALID_FILE_EXT);
	data->matrix = allocate_matrix(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	line = get_next_line(fd);
	next_line = NULL;
	while (line != NULL)
	{
		next_line = get_next_line(fd);
		get_dots_from_line(line, data->matrix, y);
		y++;
		free(line);
		line = next_line;
	}
	data->matrix[y] = NULL;
	close(fd);
}
