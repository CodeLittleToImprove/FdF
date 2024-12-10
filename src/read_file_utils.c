/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:24:09 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/06/07 18:24:09 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	handle_empty_or_null_line(char *line, int fd)
{
	if (line != NULL)
		free(line);
	close(fd);
	exit(1);
}

int	safe_str_to_int(const char *nbr_str)
{
	long long	num;

	num = ft_atoll(nbr_str);
	if (num > INT_MAX)
		return (INT_MAX);
	else if (num < INT_MIN)
		return (INT_MIN);
	return ((int)num);
}

bool	is_fdf_file(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".fdf", 4) != 0)
		return (false);
	return (true);
}
