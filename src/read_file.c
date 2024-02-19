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

//	printf("in get height\n");
	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
//	line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("height in get height:%d\n", height);
	return (height);
}

int	get_width(char	*file_name)
{
	char	*line;
	int		fd;
	int		width;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
//	printf("in get_width\n");
	if (fd < 0)
	{
		printf("file invalid?\n");
		return (-1);
	}

	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	width = ft_count_words(line, ' ');
	free(line);
	close(fd);
	printf("width in get width:%d\n", width);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**number_matrix;
	int		width_cursor;

//	printf("in fill_matrix \n");
	number_matrix = ft_split(line, ' ');
	width_cursor = 0;
	while (number_matrix[width_cursor])
	{
		z_line[width_cursor] = ft_atoi(number_matrix[width_cursor]);
//		printf("z_line[%d] = %d\n", width_cursor, z_line[width_cursor]);
		free(number_matrix[width_cursor]);
		width_cursor++;
//		printf("i in whileloop = %d\n", width_cursor);
	}
//	printf("i in fill_matrix = %d\n", width_cursor);
	free(number_matrix);
}

void	read_map_file(fdf *data, char *file_name)
{
	int		fd;
	char	*line;
	int		current_height;

//	printf("start read_file \n");
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1)); // set height of z matrix
	current_height = 0;
	while (current_height <= data->height)
		data->z_matrix[current_height++] = (int *)malloc(sizeof(int) * (data->width + 1)); // set width of z matrix
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("Error");
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
	printf("i = %d\n", current_height);
//	if (line == NULL)
//	{
//		// Handle get_next_line error
//		close(fd);
//	 // Or any suitable error code
//	}
	close(fd);
	data->z_matrix[current_height] = NULL;
	printf("finished read_file \n");
}

//int	main(int argc, char *argv[])
//{
//	fdf	*data;
//	int	i;
//	int	j;
//
//	data = (fdf *) malloc (sizeof(fdf));
//	printf("pre read_file call \n");
//	read_file(data, argv[1]);
//}