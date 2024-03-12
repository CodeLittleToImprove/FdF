/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:42:59 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/02/28 18:42:59 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"
#include <X11/keysym.h>

int	deal_key(int key, t_dot **matrix)
{
	if (key == XK_Escape)
	{
		ft_printf("%d\n", key);
		mlx_destroy_window(MATRIX_TOP_LEFT.mlx_ptr, MATRIX_TOP_LEFT.win_ptr);
		free(matrix);
		exit(0);
	}
	else
		ft_printf("%d\n", key);
	return (0);
}



//int	deal_key(int key, t_dot **matrix) working version
//{
//	ft_printf("%d\n", key);
//	return (0);
//}