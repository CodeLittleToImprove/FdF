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

//int	get_height(char	*file_name)
//{
//	char	*line;
//	int		fd;
//	int		height;
//
//	height = 0;
//	fd = open(file_name, O_RDONLY, 0);
//	if (fd < 0)
//	{
//		perror("file invalid\n");
//		return (-1);
//	}
//	line = get_next_line(fd);
//	while (line != NULL)
//	{
//		height++;
//		free(line);
//		line = get_next_line(fd);
//	}
//	close(fd);
//	return (height);
//}
//
//int	get_width(char	*file_name)
//{
//	char	*line;
//	int		fd;
//	int		width;
//
//	width = 0;
//	fd = open(file_name, O_RDONLY, 0);
//	if (fd < 0)
//	{
//		perror("file invalid\n");
//		return (-1);
//	}
//
//	line = get_next_line(fd);
//	if (line == NULL)
//		return (0);
//	width = ft_count_words(line, ' ');
//	free(line);
//	close(fd);
//	return (width);
//}
//
//void	fill_matrix(int *z_line, char *line)
//{
//	char	**number_matrix;
//	int		width_cursor;
//
//	number_matrix = ft_split(line, ' ');
//	width_cursor = 0;
//	while (number_matrix[width_cursor])
//	{
//		z_line[width_cursor] = ft_atoi(number_matrix[width_cursor]);
//		free(number_matrix[width_cursor]);
//		width_cursor++;
//	}
//	free(number_matrix);
//}

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
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		ft_error_and_exit("file does not exist");
	line = get_next_line(fd);
	if (line == NULL || ft_strlen(line) == 1)
		handle_empty_or_null_line(line, fd);
	x = ft_count_words(line, ' ');
	free(line);
	y = count_lines_and_free(fd);

	printf("x = %d y = %d \n", x, y);
	allocated_matrix = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		allocated_matrix[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
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
//		if (line != NULL)
//		free(line);
		line = get_next_line(fd);
	}
//	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}

