/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:59:51 by khakala           #+#    #+#             */
/*   Updated: 2020/01/28 15:35:38 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->cos_angle);
	*y = (*x + *y) * sin(data->sin_angle) - z;
}

void	get_color(t_fdf *data)
{
	if (data->z || data->z1)
	{
		if (data->z < 0 || data->z1 < 0)
			data->color = 0x00ffff;
		else if (data->z > 50 || data->z1 > 50)
			data->color = 0xffff05;
		else
			data->color = 15207436;
	}
	else
		data->color = 16777215;
}

void	bresenham(float x, float y, t_fdf *data)
{
	data->z = data->z_matrix[(int)y][(int)x];
	data->z1 = data->z_matrix[(int)data->y1][(int)data->x1];
	if (data->z != 0)
		data->z = data->z_matrix[(int)y][(int)x] * (data->z_alt);
	if (data->z1 != 0)
		data->z1 = data->z_matrix[(int)data->y1][(int)data->x1] * (data->z_alt);
	x *= data->zoom;
	y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	get_color(data);
	if (data->camera == 1)
	{
		isometric(&x, &y, data->z, data);
		isometric(&data->x1, &data->y1, data->z1, data);
	}
	draw_lines(x, y, data);
}

void	draw_lines(float x, float y, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x += data->shift_x;
	y += data->shift_y;
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
	x_step = data->x1 - x;
	y_step = data->y1 - y;
	max = MAX1(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				data->x1 = x + 1;
				data->y1 = y;
				bresenham(x, y, data);
			}
			if (y < data->height - 1)
			{
				data->y1 = y + 1;
				data->x1 = x;
				bresenham(x, y, data);
			}
			x++;
		}
		y++;
	}
}
