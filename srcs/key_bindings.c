/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:40:57 by khakala           #+#    #+#             */
/*   Updated: 2020/01/28 15:41:25 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *data)
{
	if (key == P)
		data->camera = 2;
	if (key == I)
		data->camera = 1;
	if (key == Q || key == E || key == ESC)
		change_z_value(key, data);
	if (key == A || key == S || key == D || key == W || key == R)
		change_angle(key, data);
	if (key == MINUS)
		data->zoom += 5;
	if (key == PLUS)
		data->zoom -= 5;
	if (key == ARROW_UP)
		data->shift_y -= 50;
	if (key == ARROW_DOWN)
		data->shift_y += 50;
	if (key == ARROW_LEFT)
		data->shift_x -= 50;
	if (key == ARROW_RIGHT)
		data->shift_x += 50;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_menu(data);
	draw(data);
	return (0);
}

int		change_z_value(int key, t_fdf *data)
{
	if (key == Q)
		data->z_alt += 2;
	if (key == E)
		data->z_alt -= 2;
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(-1);
	}
	return (0);
}

int		change_angle(int key, t_fdf *data)
{
	if (key == D)
		data->cos_angle += 0.3;
	if (key == S)
		data->sin_angle += 0.1;
	if (key == A)
		data->cos_angle -= 0.3;
	if (key == W)
		data->sin_angle -= 0.1;
	if (key == R)
		restore_defaults(data);
	return (0);
}

void	restore_defaults(t_fdf *data)
{
	data->z_alt = 1;
	data->zoom = 30;
	data->cos_angle = 0.8;
	data->sin_angle = 0.8;
	data->shift_x = 900;
	data->shift_y = 400;
	data->camera = 1;
	draw(data);
}

void	print_menu(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1450,
		50, 173255047, "Arrow keys = Move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1450,
		100, 173255047, "'+' = Zoom in '-' = Zoom out");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1450,
		150, 173255047, "AWSD = Change the angle of the projection");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1450,
		200, 173255047, "Q = Increase altitude E = decrease altitude");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1450,
		250, 173255047, "P/I = Change the projection type");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 1450,
		300, 173255047, "R = Reset to default values");
}
