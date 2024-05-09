/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:29:52 by tbui-quo          #+#    #+#             */
/*   Updated: 2024/03/17 21:29:52 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	print_help(t_dot param)
{
	char	*menu_text;

	menu_text = "To move object use arrow keys";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 20, 20, 0xC0C0C0, menu_text);
	menu_text = "To zoom in and out use + -";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 20, 40, 0xC0C0C0, menu_text);
	menu_text = "To turn off isometric view press i";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 20, 60, 0xC0C0C0, menu_text);
}