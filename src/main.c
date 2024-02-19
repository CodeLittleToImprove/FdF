/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:44:17 by tbui-quo          #+#    #+#             */
/*   Updated: 2023/07/04 18:07:18 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	main(int argc, char *argv[])
{
	fdf	*data;
	int	i;
	int	j;

	data = (fdf *) malloc (sizeof(fdf));
	if (data == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return (0);
	}
//	printf("pre read_map_file call \n");
//	printf("filename:%s \n ",argv[1]);
	read_map_file(data, argv[1]);
//	printf("after read_map_file call \n");
	i = 0;
//	printf("data->height is: %d\n", data->height);
//printf("in main \n");
	while (i < data->height)
	{
//		printf("outer while loop i = %d\n", i);
		j = 0;
		while (j < data->width)
		{
//			printf("inner while loop j = %d\n", j);
//			printf("z_matrix[%d][%d] = %d \n", i, j, data->z_matrix[i][j]);
			ft_printf("%d ", data->z_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
//	printf("never here");
//free(data);
	if (argc == 100)
		return (-10);
}
