/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:54:26 by khakala           #+#    #+#             */
/*   Updated: 2020/01/17 13:37:20 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *data)
{
	if (key == 12 || key == 14)
		change_z_value(key, data);
	if (key == 0 || key == 1 || key == 2 || key == 13)
		change_angle(key, data);
	if (key == 69)
		data->zoom += 5;
	if (key == 78)
		data->zoom -= 5;
	if (key == 126)
		data->shift_y -= 50;
	if (key == 125)
		data->shift_y += 50;
	if (key == 123)
		data->shift_x -= 50;
	if (key == 124)
		data->shift_x += 50;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(-1);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		change_z_value(int key, t_fdf *data)
{
	if (key == 12)
		data->z_alt += 2;
	if (key == 14)
		data->z_alt -= 2;
	return (0);
}

int		change_angle(int key, t_fdf *data)
{
	if (key == 2)
		data->cos_angle += 0.1;
	if (key == 1)
		data->sin_angle += 0.1;
	if (key == 0)
		data->cos_angle -= 0.1;
	if (key == 13)
		data->sin_angle -= 0.1;
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf *data;

	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_map(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FdF");
	data->zoom = 20;
	data->z_alt = 1;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
