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

void	ft_free_array(char *array[])
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	compare_sign(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}