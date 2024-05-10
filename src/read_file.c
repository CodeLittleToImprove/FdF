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

int	count_lines_and_free(int fd)
{
	int		y;
	char	*line;

	y = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	return (y);
}

int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x] != NULL)
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**allocate_matrix(char *file_name)
{
	t_dot	**allocated_matrix;
	size_t	x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error_and_exit("file does not exist or no permission");
	line = get_next_line(fd);
	if (line == NULL || ft_strlen(line) == 1)
		handle_empty_or_null_line(line, fd);
	x = ft_count_words(line, ' ');
	free(line);
	y = count_lines_and_free(fd);
//	printf("x = %d y = %d \n", x, y);
	allocated_matrix = (t_dot **)malloc(sizeof(t_dot *) * (++y));
	while (y > 0)
		allocated_matrix[--y] = (t_dot *)malloc(sizeof(t_dot) * (++x));
	close(fd);
	return (allocated_matrix);
}

t_dot	**read_map_file(char *file_name) // find memory leak later
{
	t_dot	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = allocate_matrix(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		get_dots_from_line(line, matrix_of_dots, y++);
		line = get_next_line(fd);
	}
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}
