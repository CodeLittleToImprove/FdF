//#include "../lib/fdf.h"
//
//void	read_file(fdf *data, char *file_name)
//{
//	int		fd;
//	char	*line;
//	int		i;
//
//	printf("start read_file \n");
//	data->height = get_height(file_name);
//	data->width = get_width(file_name);
//	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
//	i = 0;
//	while (i <= data->height)
//		data->z_matrix = (int *)malloc(sizeof(int) * (data->width + 1));
//	fd = open(file_name, O_RDONLY, 0);
//	i = 0;
//	line = get_next_line(fd);
//	while (line != NULL)
//	{
//		fill_matrix(data, line);
//		free(line);
//		line = get_next_line(fd);
//	}
////	if (line == NULL)
////	{
////		// Handle get_next_line error
////		close(fd);
////	 // Or any suitable error code
////	}
//	close(fd);
//	data->z_matrix[i] = NULL;
//	printf("finished read_file \n");
//}
