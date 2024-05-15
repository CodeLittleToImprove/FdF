/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:03:16 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/02/27 18:03:16 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_error_and_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	handle_empty_or_null_line(char *line, int fd)
{
	if (line != NULL)
		free(line);
	close(fd);
	exit(1);
}

void	free_matrix(t_dot **matrix_of_dots)
{
	size_t	rows;
	size_t	i;

	rows = 0;
	i = 0;
	if (matrix_of_dots == NULL)
		return ;
	while (matrix_of_dots[rows] != NULL)
		rows++;
	rows = rows - 1;
	while (i < rows)
	{
		free(matrix_of_dots[i]);
		i++;
	}
}

int	compare_sign(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}
