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

int	get_height(char	*file_name)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		perror("file invalid\n");
		return (-1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char	*file_name)
{
	char	*line;
	int		fd;
	int		width;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		perror("file invalid\n");
		return (-1);
	}

	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	width = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**number_matrix;
	int		width_cursor;

	number_matrix = ft_split(line, ' ');
	width_cursor = 0;
	while (number_matrix[width_cursor])
	{
		z_line[width_cursor] = ft_atoi(number_matrix[width_cursor]);
		free(number_matrix[width_cursor]);
		width_cursor++;
	}
	free(number_matrix);
}

void	read_map_file(fdf *data, char *file_name)
{
	int		fd;
	char	*line;
	int		current_height;


	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1)); // set height of z matrix
	current_height = 0;
	while (current_height <= data->height)
		data->z_matrix[current_height++] = (int *)malloc(sizeof(int) * (data->width + 1)); // set width of z matrix
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("Error in reading map file");
		exit(EXIT_FAILURE);
	}
	current_height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matrix(data->z_matrix[current_height], line);
		free(line);
		current_height++;
		line = get_next_line(fd);
	}
	close(fd);
	data->z_matrix[current_height] = NULL;
}

